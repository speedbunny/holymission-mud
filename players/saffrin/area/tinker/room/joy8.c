inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing along the west edge of Joy's Park.  There are several hedges "+
         "scattered about the area.  There are birds whistling off in the distance, "+
         "singing a sweet song.  The sun shines brightly overhead, warming the entire "+
         "area.  A light breeze softly blows by you.\n";
    dest_dir = ({
      TINK+"room/joy9", "north",
      TINK+"room/joy7", "south",
      TINK+"room/joy11", "east",
      "/room/eastroad5", "west",
    });
    items =({
      "hedges", "Dark green hedges",
      "sun", "ARGH!!!!!!  Your melted eyeballs slide down your face"
      "breeze", "You can see a breeze.  Silly!",
    });
    clone_list=({
          1, 1, "chipmunk", TINK+"npc/chipmunk", 0,
    });
    ::reset();
    replace_program("room/room");
}
