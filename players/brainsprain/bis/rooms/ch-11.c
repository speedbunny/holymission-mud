inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "Along the western wall are several slits, about three inches wide and "+
    "twelve inches high.  Along the eastern wall is a case with a glass face "+
    "To the south the hallway darkens but to the north the hall is well lit.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-12.c","north",
    br+"/ch-10.c","south",
  });
  items = ({
    "hall",
    "The western hallway of Castle Bismarck",
    "hallway",
    "The western hallway of Castle Bismarck",
    "bows",
    "In case of an emergency these can be used the defend the castle",
    "arrows",
     "In case of an emergency these can be used the defend the castle",
    "wall",
    "The western wall has arrow slits used to defend the castle",
    "bismarck",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",  
    "slits",
    "Slits in the wall through which arrows can be shot",
    "case",
    "A security case containing bows and arrows",
  });
  ::reset(arg);
  replace_program("room/room");
}

