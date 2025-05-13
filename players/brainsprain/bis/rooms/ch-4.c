inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "Here the floor is covered with wooden slats about six feet long and one "+
    "foot wide.  There are several tapestries hanging from the walls concealing "+
    "the rough hewn stone blocks that form the walls.  Several of the "+
    "tapestries are so old that they are beginning to rot.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-5.c","west",
    br+"/ch-3.c","east",
  });
  items = ({
    "walls",
    "The walls are made of rough hewn stone.",
    "stone",
    "Rough hewn stone that forms the walls",
    "floor",
    "The floor is composed of flagstones covered in wooden slats",
    "flagstones",
    "Big stones",
    "slats",
    "Pieces of wood fit together to make the floor look better",
    "tapestry",
    "One of many tapestries hanging from the walls here",
  });
  ::reset(arg);
  replace_program("room/room");
}
