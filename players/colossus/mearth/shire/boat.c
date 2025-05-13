inherit "/room/room";

int moving;

set_moving(arg){ moving=arg; }
int query_moving(){ return moving; }

void reset(int arg){
    ::reset(arg);
    if(!present("bonn")){
	move_object(clone_object(
	    "/players/colossus/mearth/shire/bmaster"), this_object());
    } 
    if(arg) return;
    property = ({"no_teleport", "no_clean_up" });
    set_light(1);
    short_desc = "On a boat";
    long_desc =
    "You are on a small boat that sails between the Shire and a small\n"+
    "island off it. The wooden boards that made up this boat are sort\n"+
    "of old but still seaworthy. To leave just type 'disembark'.\n";

}

void init(){
    ::init();
    add_action("disembark", "disembark");
}

int disembark(){
    object temp, boat1, boat2, there1, there2;

    temp=clone_object("/obj/treasure");
    move_object(temp, "/players/colossus/mearth/shire/pier2");
    there1=environment(temp);
    move_object(temp, "/players/colossus/mearth/shire/island1");
    there2=environment(temp);
    destruct(temp);
    boat1=present("boat", there1);
    boat2=present("boat", there2);
    if(boat1){
	if(moving){
	    write("The boat is moving.\n");
	    return 1;
	}
	write("You leave the boat.\n");
	this_player()->move_player("out of the boat#/players/colossus/mearth/shire/pier2");
	tell_room(this_object(),
	  this_player()->query_name()+" disembarks.\n");
	return 1;
    }
    else if(boat2){
	if(moving){
	    write("The boat is moving.\n");
	    return 1;
	}
	write("You leave the boat.\n");
	this_player()->move_player("out of the boat#/players/colossus/mearth/shire/island1");
	tell_room(this_object(),
	  this_player()->query_name()+" disembarks.\n");
	return 1;
    }
    else {
	if(moving){
	    write("The boat is moving.\n");
	    return 1;
	}
	this_player()->move_player("bugged#/players/colossus/temp");
	return 1;
    }
}
