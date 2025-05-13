inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "A road leading up the mountainside";
  long_desc =
"This is the side of a vast mountain. At the foot of the mountain "+
"the road turns into set of stairs cut into the mountain. To "+
"the west the road turns into a path leading in the center of Towpath, "+
"the trading center of the Bismarck Empire.\n";
  set_light(1);
  dest_dir = ({
    br+"/begin_path","south",
    br+"/town_road1","west",
    br+"/ledge","up"
  });
  items = ({
    "mountain","Mount Kladash, on which Bismarck Keep resides",
    "stairs","Stairs carved out of the living stone",
    "road","A well paved road",
    "foot","The foot of Mount Kladash",
    "path","A path leading into Towpath",
    "towpath","The Town of Towpath",
    "center","The town center of Towpath",
  });
  ::reset(arg);

    replace_program("room/room");
}
