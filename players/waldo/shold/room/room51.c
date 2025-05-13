#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Goblin area.";
    long_desc=
    "Torches placed on the walls at frequent intervals light this huge\n"+
    "chamber. Two massive stone columns rise from the arena floor to \n"+
    "support the roof. The arena floor is slightly depressed from the main\n"+
    "floor, and is smeared with large puddles of blood.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall11","northeast",
    STRONGHOLD+"/room/hall12","east",
    STRONGHOLD+"/room/hall13","southeast",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
