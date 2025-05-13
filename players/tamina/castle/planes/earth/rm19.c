inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (arg) return 0;

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(1);
	short_desc = "";
	long_desc = 
"    You come to another choice of paths here.\n"+
"    The routes branch in perfect symmetry north and south.\n"+
"    You can feel a defninite heat source coming from the north.\n";

     	dest_dir = ({
      EARTH + "rm21", "north",
      EARTH + "rm20", "south",
      EARTH + "rm17", "west",
	});

  ::reset(arg);
  RPR("room/room");
}
