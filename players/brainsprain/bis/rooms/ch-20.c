inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "End of Bismarck Hall";
  long_desc =
    "To the north is the entrance to the jail tower of Bismarck Keep.  The "+
    "hall ends here and leads to the west.  The walls are beginning to fall "+
    "apart.  The mortar holding the flagstones together has begun to rot.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-4-1.c","north",
    br+"/ch-19.c","west",
  });
  items = ({
    "entrance",
    "The entrance to the jail tower of Bismarck Keep",
    "tower",
    "The jail tower of Bismarck Keep",
    "keep",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "walls",
    "Delapitated walls",
    "mortar",
    "It has begun to rot",
    "flagstones",
    "Old hunks of stones",
  });
  ::reset(arg);
  replace_program("room/room");

}
