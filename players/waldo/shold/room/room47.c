#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Cleric's sitting room.";
    long_desc=
    "The floor of this room is padded by several huge bearskins, and four\n"+
    "soft chairs surround a low table. On the walls are niches for two\n"+
    "dozen candles, and a shelf holding four goblets and two bottles of\n"+
    "wine. Both the goblets and bottles are EXTREMELY FRAGILE.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall31","east",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
