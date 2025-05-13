#include "/players/ted/defs.h"

inherit "room/room";
int door_is_open, door_is_locked;

reset(arg) {
    ::reset(arg);
    door_is_open = 0;
    door_is_locked = 1;
    if(!arg) {
	set_light(0);
	short_desc = "Dungeon";
	long_desc =
	"The walls of this room are made of stone blocks cemented together\n"+
	"by some type of morter. Rivlets of water run and drip from the\n"+
	"walls and ceiling. The smell of torture and death hangs heavy in\n"+
	"the air. There is a cell door to the west.\n";
	dest_dir = ({
	  FIRE + "estairs","up"
	});
    }
}

long(str) {
    ::long(str);
    if(str == "door") {
	if(door_is_open)
	    write("The door is open.\n");
	else
	    write("The door is closed.\n");
    }
}

init() {
    ::init();
    add_action("open","open");
    add_action("west","west");
    add_action("unlock","unlock");
}


id(str) {
    if(::id(str)) return 1;
    return str == "door";
}

open(str) {
    if (str && str != "door")
	return 0;
    if (door_is_open)
	return 0;
    if (door_is_locked) {
	write("The door is locked.\n");
	return 1;
    }
    door_is_open = 1;
    write("Ok.\n");
    say(capitalize(this_player()->query_name())+" opened the door.\n");
    return 1;
}

unlock(str) {
    if (str && str != "door")
	return 0;
    if (door_is_open || !door_is_locked)
	return 0;
    if (!present("fire_key", this_player())) {
	if (present("key", this_player()))
	    write("You don't have the right key.\n");
	else
	    write("You need a key.\n");
	return 1;
    }
    door_is_locked = 0;
    write("Ok.\n");
    say(capitalize(this_player()->query_name())+" unlocked the door.\n");
    return 1;
}

west() {
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "west#players/ted/fire/cell");
    return 1;
}

query_door() {
    return !door_is_open;
}

open_door_inside() {
    door_is_locked = 0;
    door_is_open = 1;
}
