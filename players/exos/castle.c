#define NAME "exos"
#define DEST "/players/exos/workroom"
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
        short_desc="A small Amish dirt path leads into a black hole.";
        long_desc=
               "This small road weaves and winds in typical Pennsylvania fashion.\n"+
               "It looks like it leads to a Black Hole in space!\n";
        items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
              });
    }
    move_object(this_object(), DEST);
}

init() {
    ::init();
   add_action("enter", "path");
}

enter(str) {
    if (!id(str))
	return 0;
      this_player()->move_player("on the path#players/exos/path");
    return 1;
}
