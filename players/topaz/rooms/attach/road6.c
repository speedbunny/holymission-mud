inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are on a corner of Village Road South.\n" +
              "There are trees to the west and the south.\n" +
              "A big building is northeast of here.\n" +
              "Village Road South goes east and north from here.\n";

    dest_dir=({ATTACH + "road5","north",
               ATTACH + "road7","east",
    });
    items=({"road","It gets used a lot",
            "tree","Huge maple trees and mighty oaks are here",
            "trees","There are big willow trees and some fine maples",
            "building","It looks like an important place",
            "big building","It looks like an important place",
            "corner","A signpost says this is Village Road South",
            "signpost","It seems Village Road South goes north and east",
    });
    set_light(1);
    smell="The light, clean smell of the trees has a relaxing effect on you.";
return 1;
RR;
}
