inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Dungeon Stairs";
    long_desc =
    "A set of dank stairs windes its way down into darkness.\n"+
    "An ice cold wind carries a foul reek up from the darkness.\n";

    dest_dir = ({
      TFIRE + "dungeon","down",
      TFIRE + "ehall1","south",
    });

    items = ({
      "stair","The stairs are dark and moisture has condensed on the walls",
      "stairs","The stairs are dark and moisture has condensed on the walls"
    });

    ::reset(arg);
    replace_program("room/room");
}
