#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
object MONS;
  if (!arg)
  {
    set_light(0);
    short_desc="Inside the cave";
    long_desc=
	"You stand somewhere in the huge cave system. A faint\n"+
	"glow is reflected from the walls. You sense an eerie\n"+
	"feeling about the place.\n"+
	"You can see a hole in the ground here.\n";

    dest_dir=({
	MYAREA+"/room/l36","northeast",
      MYAREA+"/room/l41","down",
	});

    MONS=CLONE(MYAREA+"/monster/stair_ogre");
    MONS->set_level(12);
    MOVE(MONS,TO);
    }
  }
init()
{
  ::init();
  }
