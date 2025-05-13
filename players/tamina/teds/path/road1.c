inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  set_light(1);
  short_desc = "Brick Road";
  long_desc =
    "This short brick road ends here. There is a shop to the south,\n"+
    "and a strange shop to the north.  You can hear all manner of\n"+
    "clanging and hissing coming from the shop to the west...\n";

  dest_dir = ({
      TPATH + "alchemist", "north",
      TPATH + "magic", "south",
      TPATH + "path1", "east",
      TPATH + "artificer", "west",
    });

  ::reset(arg);
  replace_program("room/room");
}
