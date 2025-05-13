#define NAME "blade"
#define DEST "/players/blade/workroom"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Castle of " + NAME;
        long_desc=
            "This is the "+short_desc+".\n"+
            NAME + " is a rather new wizard, but it is an amazing castle\n"+
            "just the same. However, the gates are closed.\n";
        items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
              });
    }
    move_object(this_object(), DEST);
}

init() {
    ::init();
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}
