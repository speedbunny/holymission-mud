inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tower Stairs";
    long_desc =
    "A set of stone stairs curves up the side of the tower.\n"+
    "You can hear the wind whistling through the tower above you.\n";

    dest_dir = ({
      TFIRE + "etower_top","up",
      TFIRE + "ehall3","north",
    });

    items = ({
      "stairs","The stairs look well used. They are cut from the wall of the"+
      "tower. They wind up out of sight",
      "stair","The stairs look well used. They are cut from the wall of the"+
      "tower. They wind up out of sight"
    });

    ::reset(arg);
    replace_program("room/room");
}
