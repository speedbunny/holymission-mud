#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(0);
    short_desc="Inside the cave";
    long_desc=
	"You stand somewhere in the huge cave system. A faint\n"+
	"glow is reflected from the walls. You sense an eerie\n"+
	"feeling about the place.\n";

    dest_dir=({
	MYAREA+"/room/l41","north",
	MYAREA+"/room/l45","east",
	MYAREA+"/room/l51","south",
	MYAREA+"/room/l43","west",
	});

    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    }
  }

init()
{
  ::init();
  }
