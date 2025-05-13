inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Privy";
  long_desc =
      "You are in the privy of the Mage Tower.  At the south wall is a large "+
      "copper tub filled with steaming water.  There is an odd looking bench "+
      "against the east wall.  A large bowl of water inside a pitcher is sitting on "+
      "top of a table on the west wall.  Towels hang off the sides of the "+
      "table.\n";
  dest_dir=({
      TOWER+"room/hall5", "north",
    });
  items=({
      "tub", "A large copper tub filled with steaming water",
      "water", "Steaming water filling the tub",
      "bench","An odd bench with a cesspit in it",
      "cesspit", "EWWW!!!  A hole filled with mages' bodily waste",
      "waste", "ICK!!!!!!!!",
      "bowl", "A bowl filled with a pitcher in it",
      "pitcher", "A pitcher used for cleaning",
      "table", "A table with hooks on it sides",
      "hooks", "Hooks with towels hanging on them",
      "towels", "Large green towels",
  });
  ::reset();
  replace_program("room/room");
}
