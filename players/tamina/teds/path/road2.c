inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  set_light(1);
  short_desc = "Brick Road";
  long_desc =
    "This short brick road ends here. There is\n"+
    "a pub to the north and a shop to the south.\n";

  dest_dir = ({
      TPATH + "path1","west",
      TPATH + "pub","north",
      TPATH + "shop","south",
    });

  ::reset();
  replace_program("room/room");
}
