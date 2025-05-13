inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing in the southwest corner of Joy's Park.  There is a large pole "+
         "reaching to the sky with long ribbons flowing from the top.  The ribbons are "+
         "a variety of colors, flapping in the soft breeze.  There is a bird perched at "+
         "the top of the pole, peering down at you.\n";
    dest_dir = ({
      TINK+"room/joy8", "north",
      TINK+"room/joy6", "east",
    });
    items =({
      "pole", "A beautiful pole with ribbons flowing from its top",
      "ribbons", "Colorful ribbons billowing in the wind",
      "bird", "A tiny bird who is peering down at you",
      "breeze", "Do you honestly think you can see a breeze?",
      "sky", "As you look up at the sky, a bird fies by and plops in your eye",
    });
    clone_list=({
          1, 1, "cardinal", TINK+"npc/cardinal", 0,
    });
    ::reset();
    replace_program("room/room");
}
