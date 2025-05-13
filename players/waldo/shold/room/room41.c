#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Empty cell";
    long_desc=
    "At one time, this cell held a pair of dwarves that were being kept\n"+
    "for some sinister purpose. From what little you can see, the dwarves\n"+
    "have appeared to escape.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall3","north",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
