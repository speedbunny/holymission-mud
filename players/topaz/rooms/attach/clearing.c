inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A little clearing";
    long_desc="This little clearing seems to have no purpose.\n" +
              "The trees surround you, but do not feel oppressive.\n" +
              "You notice a small cave to the south.\n" +
              "Maybe there is something interesting in there?\n";

    dest_dir=({ATTACH + "path2","northeast",
               DEMONS + "entrance","south",
    });
    items=({"clearing","There are few plants in this clearing",
            "little clearing","There are few plants in this clearing",
            "cave","It looks harmless enough",
            "small cave","It looks harmless enough",
            "trees","They form a nice circular edge of the clearing",
            "tree","There are many trees",
    });
    set_light(1);
return 1;
RR;
}
