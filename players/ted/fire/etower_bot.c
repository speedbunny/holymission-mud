#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Tower Stairs";
    long_desc =
    "A set of stone stairs curves up the side of the tower.\n"+
    "You can hear the wind whistling through the tower above you.\n";
    dest_dir = ({
      FIRE + "etower_top","up",
      FIRE + "ehall3","north",
    });
    items = ({
      "stairs","The stairs look well used. They are cut from the wall of the"+
      "tower. They wind up out of sight",
      "stair","The stairs look well used. They are cut from the wall of the"+
      "tower. They wind up out of sight"
    });
    replace_program("room/room");
}
