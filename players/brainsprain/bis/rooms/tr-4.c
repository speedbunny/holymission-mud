inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  short_desc = "Town road";
  long_desc =
    "The brick road is cluttered with litter and debris.  To the east "+
    "the town wall rises up.  To the north Mount Kladash has sheared "+
    "off into a cliff.  To the south is a four way intersection. The "+
    "road continues to the west.\n";
  set_light(1);
  items = ({
    "town wall",
    "A large stone wall encircling the town",
    "cliff",
    "A sheared off face of Mount Kladash",
    "kladash",
    "Mount Kladash",
    "litter",
    "Empty waterskins and other errata",
    "debris",
    "Empty waterskins and other errata",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "brick",
    "The road is made out of brick",
    "mount",
    "The hill on which Bismarck Keep resides",
    "walls",
    "The town walls of Towpath",
    "intersection",
    "A busy intersection",
  });
  dest_dir = ({
    br+"/tr-5","west",
    br+"/tr-3","south",
  });

  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}
