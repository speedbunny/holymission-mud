#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Metal forging shop.";
    long_desc=
    "Four huge furnace fires burn along the west wall of this room. The air\n"+
    "is sooty and smoky. The fires are heating various chunks of metal, many\n"+
    "of which seem to be in the process of being shaped into weapons.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall8","north",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
