inherit "room/room";

int west_door_open;

reset(arg) {
    if(!arg) {
	short_desc="Room with black walls";
        long_desc=
	    "A room with black walls. There is a door to the east,\n" +
	    "and a door to the west.\n";
        dest_dir = ({
            "room/well", "east",
	    "room/sub/after_trap", "west",
                   });
        no_obvious_msg="";
    }
    west_door_open = 1;
}

init() {
    ::init();
    add_action("east","east");
    add_action("west","west");
    add_action("open","close");
    add_action("close","open");
    add_action("toggle_door","toggle");
}

east() {
    if (west_door_open == 1) {
	write("The door is closed.\n");
	return 1;
    }
}

west() {
    if (west_door_open == 0) {
	write("The door is closed.\n");
	return 1;
    }
}

open(str) {
    if (str != "door" && str != "west door" && str != "east door")
	return 1;
    write("There is no handle, and you can't push it up.\n");
    return 1;
}

close(str) {
    if (str != "door" && str != "west door" && str != "east door")
	return 1;
    write("There is no handle, and you can't push it closed.\n");
    return 1;
}

toggle_door() {
    write("You move the lever.\n");
    tell_room(this_object(),capitalize(this_player()->query_name())+
                            " pulled the lever.\n");
    if (west_door_open) {
	tell_room(this_object(), "The west door closed.\n" +
	    "The east door opened.\n");
	tell_room(environment(this_player()), "The west door opened.\n");
	west_door_open = 0;
    } else {
	tell_room(this_object(), "The west door opens.\n" +
	    "The east door closed.\n");
	tell_room(environment(this_player()), "The west door closed.\n");
	west_door_open = 1;
    }
  return 1;
}

query_west_door() {
    return west_door_open;
}
