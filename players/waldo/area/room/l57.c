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
	MYAREA+"/room/l50","northwest",
	MYAREA+"/room/l51","northeast",
	MYAREA+"/room/l62","southwest",
	MYAREA+"/room/l58","east",
	});

    MOVE(CLONE(MYAREA+"/monster/ogre"),TO);
    MOVE(CLONE(MYAREA+"/monster/ogre"),TO);
    }
  }

init()
{
  ::init();
  }
