inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

object ob1, ob2, ob3, ob4;

void reset(int arg) {
  ::reset(arg);
 
    if (!ob1) {
      ob1 = clone_object(MONSTER+"spider");
      MO(ob1, TO);
    }
    if (!ob2) {
      ob2 = clone_object(MONSTER+"jaguar");
      MO(ob2, TO);
    }
    if (!ob3) {
      ob3 = clone_object(MONSTER+"panther");
      MO(ob3, TO);
    }
    if (!ob4) {
      ob4 = CO(MONSTER+"bushmast");
      MO(ob4, TO);
    }
/*
    CM("spider");
    CM("jaguar");
    CM("panther");
    CM("bushmast");
*/

    if (arg) return;

    set_light(1);
    short_desc = "Koorubian rainforest";
    long_desc =
    "You are standing in the Koorubian Rainforest, and because of the dense\n"+
    "forest, you can't determine a sense of direction around here. \n"+
    "There are cracks of light coming from the dense canopy.  The sound \n"+
    "of the dangerous wildlife lurking hearabouts makes your skin crawl.\n"+
    "\n" +
    "LOOK! You can see a bright light coming from an opening. This might\n" +
    "be a way out of this forest. You also notice a sign on a post here.\n" +
    "\n";

    dest_dir= ({
      "players/nylakoorub/clearing/path/rooms/c120.c", "south",
      PATH+SOUTH+"a009.c", "west",
      PATH+SOUTH+"a011.c", "east"
    });

    items = ({
      "opening", "This appears to be an exit from this forest",
      "sign", "WARNING: This area is very dangerous and shouldn't be taken lightly",
      "canopy", "Splinters of lights piercing through the trees",
    });
}
