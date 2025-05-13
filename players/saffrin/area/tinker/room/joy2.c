inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc= "Joy's Park";
    long_desc=
         "You are standing in the northeast corner of Joy's Park.  There is a faint "+
         "chirp of a bird nearby.  The trickle of water can be heard coming from the "+
         "southwest.  There are several newly bloomed flowers growing around a small "+
         "dogwood tree.\n";
    dest_dir = ({
      TINK+"room/joy3", "south",
      TINK+"room/joy1", "west",
    });
    items = ({
      "flowers", "Several small flowers that are giving off a sweet scent",
      "tree", "A small dogwood tree with white flakey bark",
      "bark", "It is white and flakey",
    });
    ::reset();
    replace_program("room/room");
}
