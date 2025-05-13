inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tower Top";
    long_desc =
"You are on top of the west tower. Just to the east you see\n"+
"the other tower. They both flank the gates, alowing archers\n"+
"to fire their bows at anyone attacking the gate.\n";

    dest_dir = ({
      TFIRE + "wtower_bot", "down"
    });

    items = ({
"stair","The stairs look well used. They are cut from the wall of the\n"+
        "tower. They wind down out of sight",
"stairs","The stairs look well used. They are cut from the wall of the\n"+
         "tower. They wind down out of sight"
    });

    ::reset(arg);
    RPR("room/room");
}
