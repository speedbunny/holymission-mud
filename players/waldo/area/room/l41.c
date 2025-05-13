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
	"feeling about the place.\n"+
	"You see a hole in the ceiling ... but no way to reach it.\n";

    dest_dir=({
	MYAREA+"/room/l45","southeast",
	MYAREA+"/room/l44","south",
	MYAREA+"/room/l43","southwest",
	});
    items=({
      "hole","A TOTALLY unreachable hole",
      });

    }
  }

init()
{
  ::init();
  }
