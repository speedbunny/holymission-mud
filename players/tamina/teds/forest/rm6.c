inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"You are standing at the edges of the Petrified Forest, \n"+
"next to the high walls of a mountain.  You can see the \n"+
"gleaming walls of Camelot to your north.\n";

  dest_dir = ({
    TFOREST + "rm2", "south",
    TFOREST + "rm5", "west"
    });
}
