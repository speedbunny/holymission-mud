inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if(arg) return 0;
  set_light(1);
  short_desc = "Dread Forest";
  long_desc =
"The forest is especially dense here, you have to push\n"+
"through undergrowth so thick you can see no more than\n"+
"an arms length in front of you.\n";

    dest_dir = ({
    TFOREST + "rmV", "north",
    TFOREST + "rmJ", "south",
    TFOREST + "rmQ", "east"
    });

    ::reset();
    replace_program("room/room");
}
