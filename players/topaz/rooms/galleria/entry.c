inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Entry to Willieo's Galleria";
    long_desc="This is the entry hall to the famous WILLIEO'S GALLERIA!!\n" +
              "Unfortunately, it is closed right now while some major\n" +
              "renovations are taking place.\n";

    dest_dir=({ATTACH + "road3","north",
    });
    items=({"galleria","The galleria is closed right now",
            "entry hall","It looks spectacular!  Too bad this place is closed",
            "hall","It looks spectacular!  Too bad this place is closed",
    });
    set_light(1);
return 1;
RR;
}
