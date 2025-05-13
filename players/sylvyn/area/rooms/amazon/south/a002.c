inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
  ::reset(arg);

    CM("jaguar.c");
    CM("gorrila.c");

    if (arg) return;

    set_light(1);
    short_desc = "Koorubian rainforest";
    long_desc =
    "You are standing in the Koorubian Rainforest, and because of the dense\n"+
    "forest, you can't determine a sense of direction around here. \n"+
    "There are cracks of light coming from the dense canopy.  The sound \n"+
    "of the dangerous wildlife lurking hereabouts makes your skin crawl. \n" +
    "\n" +
    "LOOK! You can see a bright light coming from a opening. This might\n" +
    "be a way out of this forest. You also notice a sign on a post here.\n" +
"\n";

    dest_dir= ({
      "players/nylakoorub/clearing/path/rooms/c112.c", "south",
      PATH+SOUTH+"a001.c", "west",
      PATH+SOUTH+"a003.c", "east"


    });


    items = ({
      "opening", "This appears to be an exit from this forest",
      "sign", "WARNING: This area is very dangerous and shouldn't be taken lightly",
      "canopy", "Splinters of lights piercing through the trees",

    });

}
