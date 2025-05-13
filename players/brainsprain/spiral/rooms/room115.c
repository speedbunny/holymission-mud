inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
  short_desc = "Stairwell connecting the first and second floors";
  long_desc =
    "There is a staircase leading down in the center of this room. Water "+
    "rushes into this room and down the stairs.  In the dry, northern corner "+
    "of the room a skeleton hangs from a craggy outcrop.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room114","south",
    sr+"/room201","down",
  });
  items = ({
    "room",
    "Stairwell connecting the first and second floors",
    "outcrop",
    "A small granite shelf about ten feet off of the ground",
    "skeleton",
    "The skeleton of a long dead creature.  It is huge",
    "water",
    "Water rushing into the room and flowing down the staircase",
    "staircase",
    "Stairs going to the rooms below.",
  });
}
