inherit "room/room";
#include "/players/saffrin/defs.h"

object butterfly;

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing in the northwest corner of Joy's Park.  There are several "+
         "marble tables about.  There is flowers surrounding the tables in sweet patterns "+
         "of hearts and angels.  The flowers are giving off a sweet scent that "+
         "is pleasing to your senses.\n";
    dest_dir = ({
      TINK+"room/joy8", "south", 
      TINK+"room/joy10", "east",
    });
    items =({
      "tables", "White marble tables",
      "flowers", "sweet smelling flowers",
      "hearts", "Flowers are arranged in heart patterns",
      "angels", "Flowers arranged in angel patterns",
    });
    clone_list=({
          1, 1, "butterfly", TINK+"npc/butterfl", 0,
    });
    ::reset();
    replace_program("room/room");
}
