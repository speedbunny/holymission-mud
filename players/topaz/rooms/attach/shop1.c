inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A small shop";
    long_desc="This shop isn't quite finished yet.\n" +
              "Please come back when it is open for business though.\n";

    dest_dir=({ATTACH + "road8","west",
    });
    items=({"shop","It isn't open for business yet",
    });
    set_light(1);
return 1;
RR;
}
