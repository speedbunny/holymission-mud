#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Bugbears' Quarters";
    long_desc=
    "You enter the Bugbears' quarters. The room contains 6 beds, a\n"+
    "table on which lie three empty bowls, and an old but sturdy\n"+
    "chest.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall2","north",
              });

    }
  }

init()
{
  ::init();
  return 1;
  }
