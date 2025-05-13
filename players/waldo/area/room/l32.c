#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(0);
    short_desc="Inside the cave";
    long_desc=
"You have stumbled into the territory of the Goony-Goo-Goo\n"+
"Goblins. They seem to be mightily displeased that you are here\n"+
"and have disturbed them. Perhaps, for your survival, you should\n"+
"leave this place.\n";

    dest_dir=({
	MYAREA+"/room/l33","south",
	MYAREA+"/room/l34","southeast",
	});

    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    }
  }

init()
{
  ::init();
  }
