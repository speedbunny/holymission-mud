inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  
  short_desc = "Bismarck Hall";
  long_desc =
    "Your footsteps echo while you walk down the hall.  The walls and floor\n"+
    "here are smooth from the wear of hands and feet.  The walls are unadorned\n"+
    "and covered in condensation.  The moisture in the air combined with the\n"+
    "chilly temperature make this an unpleasant room.\n";
  set_light(1);
  items = ({
    "hall",
    "The southern hallway of Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "walls",
    "They have been smoothed down over the years",
    "floor",
    "It is so smooth it is almost slippery",

  });
  dest_dir = ({
    br+"/ch-8.c","west",
    br+"/ch-6.c","east",
  });
  
  clone_list = ({ 
    1, 2, "guard", bm+"/guard.c", 0 
  });
  ::reset(arg);
  replace_program("room/room");
}
