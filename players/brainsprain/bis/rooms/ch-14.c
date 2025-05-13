inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "Two large candleabra's are the predominate source of light in this "+
    "hallway.  They are composed of solid iron and are firmly bolted to the "+
    "ground.  A red carpet runs through the length of the room, spanning "+
    "east to west.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-15.c","east",
    br+"/ch-13.c","west",
  });
  items = ({
    "candleabra's",
    "Two antique candle holders",
    "carpet",
    "The red carpet of welcome",
  });
  
  clone_list = ({ 
    1, 2, "guard", bm+"/guard.c", 0 
  });
  ::reset(arg);
  replace_program("room/room");
}

