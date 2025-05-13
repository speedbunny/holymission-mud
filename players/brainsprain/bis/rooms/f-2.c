inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Bismarck Hunting Reserve";
  long_desc = "The path continues here and winds slightly to the north.  The oak and "+
              "poplar trees are the most prevalent here.  The path is slowly beginning to "+
              "fade and soon you will be walking in the woods.  You notice some old deer "+
              "tracks here.\n";
  set_light(1);
  items = ({
    "oaks","Huge oak trees",
    "poplars","Huge poplar trees",

    "woods","An old growth forest",
    "path","Little more than crushed grass now",
    "tracks","Heart shaped foot prints",
  });
  dest_dir = ({
    br+"/f-1.c","west",
    br+"/f-3.c","east",
  });
  ::reset(arg);

    replace_program("room/room");
}
