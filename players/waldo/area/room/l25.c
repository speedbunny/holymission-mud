#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
object MONS;
  if (!arg)
  {
    set_light(1);
    short_desc="Inside the cave";
    long_desc=
	"You stand somewhere in the huge cave system. A faint\n"+
	"glow seems to permeate from the walls. You sense an\n"+
	"eerie feeling about the place.\n"+
	"You notice some stairs leading down from here.\n";

    dest_dir=({
	MYAREA+"/room/l27","south",
	MYAREA+"/room/l31","down",
	});

    MONS=CLONE(MYAREA+"/monster/stair_ogre");
    MONS->set_level(7);
    MOVE(MONS,TO);
    }
  }
  
init()
{
  ::init();
  }
