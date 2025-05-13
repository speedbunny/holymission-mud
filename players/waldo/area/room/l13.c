#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc="Inside the cave";
    long_desc=
"You have reached a dead-end. You can only go to where you came\n"+
"from. You hold your nose in disgust of the foul smelling pile\n"+
"of orcish waste that lies in the corner.\n";

    items=({
      "waste","A huge pile of foul smelling orcish droppings",
      "pile","A reeking lump of waste",
        });
    dest_dir=({
	MYAREA+"/room/l16","south",
	});

    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    MOVE(CLONE(MYAREA+"/monster/orc"),TO);
    }
}

init()
{
  ::init();
  }
