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
	MYAREA+"/room/l41","northwest",
	MYAREA+"/room/l46","east",
	MYAREA+"/room/l51","southwest",
	MYAREA+"/room/l44","west",
	});

    }
  }

init()
{
  ::init();
  }
