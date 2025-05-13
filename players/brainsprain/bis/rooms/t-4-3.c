inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Third floor of northeastern tower";
  long_desc =
    "This room serves as guard room for the royal cell just above.  There is "+
    "A staircase leading up to a door that is currently open.  A desk sits "+
    "against the wall and a chair leans up against it.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-4-2.c","down",
    br+"/t-4-4.c","up",
  });
  items = ({
    "room",
    "The guard room for the royal cell just above",
    "wall",
    "Wall of the guard room",
    "staircase",
    "A winding staircase",
    "door",
    "An solid oak door",
    "desk",
    "An ancient oak desk",
    "chair",
    "An ancient oak chair",
  });
  clone_list = ({ 1, 1, "guard", bm+"/guard.c", 0 });
  ::reset(arg);
  replace_program("room/room");
}
