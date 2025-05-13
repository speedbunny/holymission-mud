#define C(x) capitalize(x)
#define PATH "/players/warlord/house"
#define TPN this_player()->query_name()

inherit "room/room";

string allowed;

void reset(int arg) {
    if(arg) return;
    set_light(1);
    short_desc="Master bedroom.\n";
    long_desc=
    "This is the master bedroom. To the north is a balcony and south is\n"+
    "a walkin closet. To the east is the master bathroom and west the landing.\n"+
    "The room is well furnished with all the needs a person could want. In \n"+
    "corner you can see Rachel's vanity. Across the room is the king-size bed.\n"+
    "You can see a small dresser in another corner.\n";
    dest_dir=({
      PATH+"/landing","west",
      PATH+"/closet","south",
      PATH+"/balcony","north",
      PATH+"/master_bath","east",
    });
    items=({
      "vanity","This is vanity made out of pure oak. On the vanity is a jewelery box,\nhand mirror,brush and picture",
      "hand mirror","Just an ordinary mirror",
      "mirror","Just an ordinary mirror",
      "jewelry box","This is where Rachel keeps here jewelry",
      "jewelry","She has ear-rings, necklaces and bracelets",
      "brush","An ordinary hair brush",
      "picture","This is a picture of her husband warlord",
      "dresser","This a solid oak dresser",
      "bed","The bed is a four-posted white canopy bed",
      "lamp","A simple brass lamp",
    });
    allowed="igloo#rachel#warlord#";
}

void init() {
    string *names;
    ::init();
    add_action("_add", "add");
    add_action("make","make");
    add_action("_remove", "remove");
    add_action("_list", "list");
    add_action("emote","emote");
    add_action("imag","imagine");
    names=explode(allowed,"#");
    if(member_array((string)this_player()->query_real_name(),names)==-1) {
	write("The room is locked magically.\n");
	say(TPN+" tried to come in the room.\n");
	if(catch(move_object(this_player(),"players/"
	      + (string)this_player()->query_real_name() + "/workroom")))
	    move_object(this_player(),"/players/warlord/house/landing");
    }
}

status _add(string str) {
    string *names;
    if((string)this_player()->query_real_name()!="rachel"
      && (string)this_player()->query_real_name()!="warlord") return 0;
    str=lower_case(str);
    names=explode(allowed,"#");
    if(member_array(str,names)==-1) {
	allowed+=str + "#";
	write(C(str) + " is added to the allowed list.\n");
    }
    else write(C(str) + " is already permitted to enter.\n");
    return 1;
}

status _remove(string str) {
    string *names,bit1,bit2;
    if((string)this_player()->query_real_name()!="rachel"
      && (string)this_player()->query_real_name()!="warlord") return 0;
    names=explode(allowed,"#");
    if(member_array(str,names)==-1)
	write(C(str) + " isn't permitted to enter anyway.\n");
    else {
	sscanf(allowed,"%s" + str + "#%s",bit1,bit2);
	allowed=bit1 + bit2;
	write(C(str) + " is removed from the allowed list.\n");
    }
    return 1;
}

status _list() {
    string *names;
    int i;
    if((string)this_player()->query_real_name()!="rachel"
      && (string)this_player()->query_real_name()!="warlord") return 0;
    names=explode(allowed,"#");
    write("People allowed to enter are:\n\n");
    for(i=0;i<sizeof(names);i++) write(C(names[i]) + "\n");
    return 1;
}

int query_prevent_shadow() { return 1; }
emote(str) {
    if(!str) {
	write("Emote what?\n");
	return 1;
    }
    say(this_player()->query_name()+" "+str+"\n");
    write(this_player()->query_name()+" "+str+"\n");
    return 1;
}
imag(str) {
    if(!str) {
	write("What do you want to imagine?\n");
	return 1;
    }
    write(capitalize(str+".\n"));
    say(capitalize(str+".\n"));
    return 1;
}
make(str) {
    if(!str){
	write("Make what? the bed perhaps");
	return 1;
    }
    if ((str=="bed")||(str=="the bed")) {
	object ob;
	if (present("sheets",this_player())) {
	    write("You make up the bed.\n");
	    say(TPN+" makes up the bed.\n");
	    ob=(present("sheets",this_player()));
	    destruct(ob);
	    return 1;
	}
	else {
	    write("You don't have any sheets on you. Go to the linen closet and get some.\n");
	    return 1;
	}
    }
    else {
	write("You can't make that.\n");
	return 1;
    }
}
