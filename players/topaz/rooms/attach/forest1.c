inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
if(arg) return;
    short_desc="A cheery forest";
    long_desc="This forest is cheery.  You feel no evil here.\n" +
              "The trees are quite lovely and you might\n" +
              "like it here if you stayed long enough.\n";

    dest_dir=({ATTACH + "road4","south",
               ATTACH + "forest3","north",
               ATTACH + "forest2","northwest",
    });
    items=({"forest","The forest is dark, yet not oppressive",
            "tree","It looks like an oak tree",
            "trees","They are pretty",
    });
    set_light(1);
return 1;
RR;
}
