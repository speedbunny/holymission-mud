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
	MYAREA+"/room/l44","north",
	MYAREA+"/room/l45","northeast",
	MYAREA+"/room/l43","northwest",
	MYAREA+"/room/l58","south",
	MYAREA+"/room/l57","southwest",
	});
    }
  }

init()
{
  ::init();
  }
