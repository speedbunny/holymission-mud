inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A small hut";
    long_desc="This hut will be a training area when it is finished.\n" +
              "Unfortunately it is not done right now.\n" +
              "Be sure to check in the future.\n";

    dest_dir=({ATTACH + "road5","east",
    });
    items=({"hut","A small hut.  Too bad it isn't working yet",
    });
    set_light(1);
return 1;
RR;
}
