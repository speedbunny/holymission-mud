inherit "room/room";

reset(arg) {
    if(!arg) {
	short_desc="Down the well";
        long_desc=
	    "You are down the well. It is wet and slippery.\n" +
	    "There is a lever beside a door to the west.\n";
        dest_dir=({
            "room/narr_alley", "up",
	    "room/maze1/maze1", "north",
            "players/sarge/rooms/room1", "south",
                 });
        hidden_dir=({
            "room/sub/door_trap","west",
                   });
        items=({
            "lever","The lever can be moved between two positions",
            "door","@@door_desc",
              });
    }
}

door_desc() {
    if ("room/sub/door_trap"->query_west_door())
        return("The door is closed");
    else
        return("The door is open");
}

init() {
    ::init();
    add_action("west", "west");
    add_action("open", "open");
    add_action("close", "close");
    add_action("pull", "pull");
    add_action("pull", "turn");
    add_action("pull", "move");
}


west() {
    if ("room/sub/door_trap"->query_west_door()) {
        write("The door is closed.\n");
        return 1;
    }
    return ::move();
}

close(str) {
    if (!str && str != "door")
	return 0;
    write("You can't.\n");
    return 1;
}

open(str) {
    if (!str && str != "door")
	return 0;
    write("You can't.\n");
    return 1;
}

pull(str) {
    if (!str || str != "lever")
	return 0;
    call_other("room/sub/door_trap", "toggle_door");
    return 1;
}
