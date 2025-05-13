inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Bismarck Keep southern hallway";
  long_desc =
    "You have entered the hallway of Bismarck Keep.  The sounds that you "+
    "heard from the gate seems louder to the north.  However, nothing seems "+
    "to disturb the tranquility you feel in this room.  "+
    "The walls here are finished with rosewood and cedar.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-3.c","west",
    br+"/ch-1.c","east",
    
  });
  items = ({
    "keep",
    "Bismarck Keep",
    "bismarck",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "gate",
    "Huge steel gates with wrought iron hinges",
    "rosewood",
    "It is used to finish the walls",
    "cedar",
    "It is used to finish the walls",
    "mosiac",
    "They form the offical seal of the lands",
    "picture",
    "The official seal of the lands",
    "walls",
    "These walls are tiled with exotic woods",
    "floor",
    "A mosiac of tiles forming a picture",
  });
  
  clone_list = ({ 
    1, 1, "guard", bm+"/guard.c", 0 
  });
  ::reset(arg);  
  replace_program("room/room");
}
