#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Prison cell.";
    long_desc=
    "In this dingy prison cell you can see the scattered remains of many\n"+
    "hapless victims captured by the Bugbears.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall5","north",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
