inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {

    {
    CM("jaguar.c");
    CM("barba_am.c");
    }

::reset(arg);
    if (arg) return;

    set_light(1);
    short_desc = "Koorubian rainforest";
    long_desc =
    "You are standing in the Koorubian Rainforest, and because of the dense\n"+
    "forest, you can't determine a sense of direction around here. \n"+
    "There are cracks of light coming from the dense canopy.  The sound \n"+
    "of the dangerous wildlife lurking hearabouts makes your skin crawl.\n"+
    "\n";

    dest_dir= ({
       PATH+SOUTH+"a025.c", "west",
      PATH+SOUTH+"a037.c", "north",
      PATH+SOUTH+"a015.c", "south",

    });


    items = ({
      "canopy", "Splinters of lights piercing through the trees",

    });



replace_program("room/room");
}
