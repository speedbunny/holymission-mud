inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "First floor of northwestern tower";
  long_desc =
    "This room is dark and cold, moisture grips the walls and slowly drips "+
    "down.  A single torch gutters in the breeze flowing from the west "+
    "window.  A staircase winds up to the next floor, each step is covered "+
    "in rose petals.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-13.c","south",
    br+"/t-3-2.c","up",
  });
  items = ({
    "step",
    "It is covered in rose petals",
    "moisture",
    "Condensation drips down the walls",
    "room",
    "First floor of the northwestern tower",
    "tower",
    "The northwestern tower",
    "staircase",
    "A spiral staircase leading up",
    "walls",
    "These walls are covered in moisture and seem to be sweating",
    "window",
    "It is little more than an arrow slit",
    "torch",
    "A thick torch spewing forth a greasy flame",
    "petals",
    "Dainty rose petals",
  });
  ::reset(arg);
  replace_program("room/room");
}

