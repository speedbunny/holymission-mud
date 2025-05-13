inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "First floor of southeastern tower";
  long_desc =
    "Along the northern curve of this wall is an entry way into the hall. "+
    "A staircase starts next to the door and leads upwards.  The rest "+
    "of the room is dominated by stables and stalls containing arabian horses.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-3.c","north",
    br+"/t-1-2.c","up",
  });
  items = ({
    "horses",
    "Huge arabian horses",
    "room",
    "First floor of the southeastern tower",
    "tower",
    "The southeastern tower",
    "door",
    "A door leading into the hall",
    "hall",
    "The southern hall of the castle",
    "castle",
    "Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "curve",
    "The walls of this room are round, there are no corners",
    "wall",
    "The wall of the tower",
    "walls",
    "There is really only one wall, it wraps around the entire room",
    "staircase",
    "A spiral staircase leading up",
    "stables",
    "Huge stables for the horses to stand in",
    "stall",
    "Huge stalls for the horses to stand in",
  });
  ::reset(arg);
  replace_program("room/room");

}


