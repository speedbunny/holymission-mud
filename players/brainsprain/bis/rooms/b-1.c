inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "A dark basement";
  long_desc =
    "This is a long forgotten passage in Bismarck Keep.  All the torch holders "+
    "are empty.  The floor and walls are covered with a fine layer of mold. "+
    "A thin stream of water trickles down from the ceiling and spatters at "+
    "your feet.\n";
  set_light(0);
  dest_dir = ({
    br+"/t-4-1.c","up",
    br+"/b-2.c","south",
  });
  items = ({
    "floors","The floors are covered in mold",
    "walls","The walls are covered in mold",
    "passage",
    "The floors are covered with mold",
    "keep",
    "Bismarck Keep",
    "bismarck",
    "Bismarck Keep",
    "holders",
    "Torch mounts, bolted to the wall",
    "mold","A green mold",
    "water","Thick brownish water",
    "stream","A stream of Thick brownish water",
    "ceiling","A steam of water flows down from it",
  });
  ::reset(arg);
  replace_program("room/room");

}



