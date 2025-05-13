#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(0);
    short_desc="Inside the cave";
    long_desc=
"You arrive at another dead-end. However, you notice a darker opening to the\n"+
"west. This is the famed entrance to the Goony-Goo-Goo goblin stronghold.\n"+
"If you are extremely brave, you can enter and attempt to end their\n"+
"kings' evil thwarting of power. You notice some goblins standing here.\n";

    dest_dir=({
	MYAREA+"/room/l33","northeast",
	});
    items=({
      "stronghold","The goblin stronghold. You think it holds many goblins",
      "opening","A really dark opening to the stronghold",
        });

    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    MOVE(CLONE(MYAREA+"/monster/goblin"),TO);
    }
  }

init()
{
  ::init();
  }
