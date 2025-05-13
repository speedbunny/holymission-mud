inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tower Stairs";
    long_desc =
"A set of stone stairs curves up the side of the tower.\n"+
"A chill breeze drys the sweat from your brow.\n";

    dest_dir = ({
      TFIRE + "tower1", "up",
      TFIRE + "whall1", "south"
    });

    items = ({
"stair","The stairs look well used. They are cut from the wall of the\n"+
        "tower. They wind up out of sight",
"stairs","The stairs look well used. They are cut from the wall of the\n"+
         "tower. They wind up out of sight"
    });

    ::reset(arg);
    RPR("room/room");
}
