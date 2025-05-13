#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Cleric's chamber.";
    long_desc=
    "A table, bed and several chairs are visible in this room. Usually you\n"+
    "can see a hunched-back figure sitting in one of the chairs. On one wall\n"+
    "you notice a REALLY GROSS attempt at art.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall33","east",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
