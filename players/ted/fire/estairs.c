#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Dungeon Stairs";
    long_desc =
    "A set of dank stairs windes its way down into darkness.\n"+
    "An ice cold wind carrys a foul reek up from the darkness.\n";
    dest_dir = ({
      FIRE + "dungeon","down",
      FIRE + "ehall1","south",
    });
    items = ({
      "stair","The stairs are dark and moisture has condensed on the walls",
      "stairs","The stairs are dark and moisture has condensed on the walls"
    });
    replace_program("room/room");
}
