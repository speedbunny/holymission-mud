inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {

     {
     CM("python.c");
     CM("salamand.c");
     CM("spider.c");
     CM("wildboar.c");
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
      PATH+SOUTH+"a106.c", "north",
      PATH+SOUTH+"a096.c", "east",


    });


    items = ({
      "canopy", "Splinters of lights piercing through the trees",

    });



replace_program("room/room");
}
