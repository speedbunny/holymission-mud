inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "The hallway here has come to a T.  To the north the hallway continues. "+
    "To the south is the entrance to the southwestern tower. The smell of "+
    "horse is strong here.  The sound of conversation and laughter comes "+
    "from the northern hall.\n";
  set_light(1);
  items = ({
    "hallway",
    "The intersection between the southern and western hallways",
    "tower",
    "The southwestern tower",
    "entrance",
    "The entrance to the southwestern tower",
  });
  dest_dir = ({
    br+"/ch-9.c","north",
    br+"/ch-7.c","east",
    br+"/t-2-1.c","south",
  });
  ::reset(arg);
  replace_program("room/room");
}
