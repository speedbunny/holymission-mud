#define TPN this_player()->query_name()
inherit"room/room";
object openr,openo;
reset(arg) {
    if (arg) return;
    openr=(present("openr",this_player()));
    openo=(present("openo",this_player()));
    set_light(1);
    short_desc="Kitchen.\n";
    long_desc=
    "This is the kitchen where Skyler cooks her best recipes.\n"+
    "To the north is where the sink is at, just under the window. To\n"+
    "the left of sink is the oven. There is an island in the middle\n"+
    "of the room. On the south wall lies the refridgerator.\n";
    items=({
      "sink","This is a basic sink where things get washed and cleaned",
      "island","This is where Skyler cuts most of here food and prepares it",
      "oven","This is where Skyler cooks her awesome recipes",
      "refridgerator","This is where they keep things cold",
    });
    dest_dir=({
      "players/warlord/house/dining_room","east",
      "players/warlord/house/foyer","south",
      "players/warlord/house/den","west",
    });
}
init() {
    ::init();
    add_action("open","open");
    add_action("close","close");
    add_action("wash","wash");
    add_action("check","check");
    add_action("remove","raid");
}
open(str) {
    if(!str) {
	write("What would you like to open?\n");
	return 1;
    }
    if((str=="the oven")||(str=="oven")) {
	object ob;
	write("You open the oven.\n");
	say(TPN+" opens the oven.\n");
	ob=clone_object("/players/warlord/house/openo");
	move_object(ob,this_player());
        ::init();
	return 1;
    }
    if((str=="the refridgerator")||(str=="refridgerator")) {
	object ob2;
	write("You open the refridgerator.\n");
	say(TPN+" opens the refridgerator.\n");
	ob2=clone_object("players/warlord/house/openr");
	move_object(ob2,this_player());
        ::init();
	return 1;
}}
check(str) {
    if(!str) {
	write("What do you want to check?\n");
	return 1;
    }
    if((str=="the fridge")||(str=="the refridgerator")||(str=="refridgerator")||(str=="fridge")) {
	if(present("openr",this_player())) {
	    write("You look inside the refridgerator and find all kinds of food being kept fresh.\nRaid what you want and close the door.\n");
	    say(TPN+" checks inside the fridge.\n");
	    return 1;
	}
	else {
	    write("You can't check inside the fridge if the door is closed.\n");
	    return 1;
	}
    }
    else {
	write("You can't check that.\n");
	return 1;
    }
}
close(str) {
    if(!str) {
	write("What do you want to close?\n");
	return 1;
    }
    if((str=="the refridgerator")||(str=="refridgerator")) {
        if(openr) {
	    write("You close the refridgerator.\n");
	    say(TPN+" closes the fridgerator.\n");
	    destruct(openr);
            return 1;
	}
	else {
	    write("The refridgerator door is not opened.\n");
	    return 1;
	}
    }
    if ((str=="the oven")||(str=="oven")) {
	if(openo) {
	    write("You close the oven.\n");
	    say(TPN+" closes the oven.\n");
	    destruct(openo);
            return 1;
	}
	else {
	    write("The oven is not open.\n");
	    return 1;
	}
    }
}
remove(str) {
object food;
if(!str) {
write("What do you want to remove from the fridge?\n");
return 1;
}
food=clone_object("obj/food");
food->set_name(str);
food->set_short(capitalize(str));
food->set_long("This looks like "+str+" to me.\n");
food->set_strength(0);
move_object(food,this_player());
write("You raid the fridge of "+str+"\n");
say(TPN+" raids the fridge of "+str+"\n");
return 1;
}
