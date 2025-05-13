inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tower Stairs";
    long_desc =
"A set of stone stairs curves up the side of the tower.\n"+
"You can hear the wind whistling through the tower\n"+
"above you.\n";

    dest_dir = ({
      TFIRE + "wtower_top", "up",
      TFIRE + "whall4", "north"
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
