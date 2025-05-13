#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc="Inside the cave";
    long_desc=
	"You stand somewhere in the huge cave system. A faint\n"+
	"glow seems to permeate from the walls. You sense an\n"+
	"eerie feeling about the place.\n"+
      "You notice some stairs leading up here.\n";

    dest_dir=({
	MYAREA+"/room/l23","east",
	MYAREA+"/room/l19","up",
	});

    }
  }

init()
{
  ::init();
  }
