#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Subterranean stream.";
    long_desc=
    "A shallow stream runs through this room, falling through a spout in\n"+
    "the ceiling, running through a trench in the cavern floor. You think\n"+
    "that diving into the pool to see how deep it is would be a REALLY BAD\n"+
    "idea, likely to cause in death.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall5","east",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
