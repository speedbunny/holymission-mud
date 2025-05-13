inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "Small tables are set up along the southern wall with people sitting "+
    "behind them protesting various causes which affect the kingdom.  A "+
    "massive "+
    "sign hangs above the protesters.  You notice the people walking by try "+
    "to look straight ahead and ignore the protesters.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-7.c","west",
    br+"/ch-5.c","east",
  });
  items = ({
    "wall",
    "A wall made of rough hewn stone",
    "stone",
    "Rough hewn stone that composes the wall",
    "tables",
    "Tables with flyers on them",
    "people",
    "People quickly passing by the protestors",
    "sign",
    "It reads: Do not pay attention to protesters under penalty of death",
    "protesters",
    "Citizens with a death wish",
  });
  clone_list = ({ 
    1, 1, "protestor", bm+"/protestor.c", 0 
  });
  ::reset(arg);
  replace_program("room/room");
}
