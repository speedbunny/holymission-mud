inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
  
  short_desc = "A road leading up the mountainside";
  long_desc =
    "You have crested the mountain and behold an amazing site!!  In front "+
    "of you lies a path of pure gold.  It only goes a short distance, "+
    "but must be worth a fortune.  To the west is the gates of Castle "+
    "Bismarck.\n";
  set_light(1);
  dest_dir = ({
    br+"/ledge","down",
    br+"/gates","west",
  });
  items = ({
    "kladash","Mount Kladash on which Bismarck Keep resides",
    "mountain","Mount Kladash, on which Bismarck Keep resides",
    "site","You see a path of pure gold",
    "path","A path of pure gold",
    "castle","Castle Bismarck",
    "Bismarck","Castle Bismarck",
    "bismarck","Castle Bismarck",
    "gates","The gates to Castle Bismarck",
  });
  ::reset(arg);
  
  replace_program("room/room");
}

