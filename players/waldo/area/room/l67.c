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
"glow is reflected from the walls. You sense a distinctly EVIL\n"+
"feeling from the southwest.\n";

    dest_dir=({
      MYAREA+"/room/l65","north",
      MYAREA+"/room/l68","southwest",
	});

    }
  }

init()
{
  ::init();
  }
