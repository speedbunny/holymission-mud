#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Torture chamber.";
    long_desc=
    "A torture rack, featuring all the usually types of toys, from iron\n"+
    "maidens, to prongs and tongs with steel sharpened tips litter the\n"+
    "floor. A huge pot of boiling oil gives further evidence to the purpose\n"+
    "of this room.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall27","north",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
