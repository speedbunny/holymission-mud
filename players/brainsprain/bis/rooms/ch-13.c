inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "The hallway here splits into a T.  To the south and east the hall "+
    "continues.  To the north is the entrance into the northwestern tower.  "+
    "A red carpet starts here and leads down the northern hall.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-14.c","east",
    br+"/ch-12.c","south",
    br+"/t-3-1.c","north",
  });
  items = ({
    "hall",
    "The northern hall",
    "hallway",
    "The intersection between the western and northern hallways",
    "entrance",
    "Entrance to the northwestern tower",
    "tower",
    "The northwestern tower",
    "carpet",
    "The red carpet of welcome",
  });
  ::reset(arg);
  replace_program("room/room");
}
