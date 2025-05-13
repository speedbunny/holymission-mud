inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="Village Road South";
    long_desc="You are at a corner on Village Road South.\n" +
                "A big building is northwest of here, a small\n" +
                "shop east of here and a cute little house is to the south.\n" +
                "Village Road South goes north and west from here.\n";

    dest_dir=({ATTACH + "road9","north",
               ATTACH + "fhouse","south",
               ATTACH + "road7","west",
               ATTACH + "shop1","east",
    });
    items=({"road","The road gets much use",
            "big building","You should really find out what's in it",
            "building","You should really find out what's in it",
            "corner","A signpost says this is Village Road South",
            "signpost","It seems Village Road South goes north and west",
            "shop","It looks a little dark inside",
            "house","It has some flowers growing in a small garden out front",
            "flowers","They are bright and beautiful",
            "garden","It looks well tended",
    });
    set_light(1);
    smell="You smell tulips and marigolds.";
return 1;
RR;
}
