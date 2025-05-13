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
"feeling about this place. You see a large pile of bones to\n"+
"one side. You wonder how they got there.\n";

    dest_dir=({
	MYAREA+"/room/l47","north",
	MYAREA+"/room/l48","northeast",
	MYAREA+"/room/l59","southwest",
	});

    items=({
      "bones","A large pile made of the bones of dead adventurers",
      "pile","A large collection of bones",
        });

    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/meanorc"),TO);
    MOVE(CLONE(MYAREA+"/monster/meanorc"),TO);
    MOVE(CLONE(MYAREA+"/monster/meanorc"),TO);
    MOVE(CLONE(MYAREA+"/monster/ogre"),TO);
    }
  }

init()
{
  ::init();
  }
