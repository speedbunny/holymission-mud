inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (!arg)
  {
      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "In a tunnel";
	long_desc = 
"    Here in the tunnel, you can see that the formation of the walls of\n"+
"    the tunnel are gradually changing, toi a mixture with more solid\n"+
"    rock, and less Earth.  You can see that this effect continues along\n"+
"    the tunnel to the south-west.\n";

     	dest_dir = ({
      EARTH + "rm4", "north",
      EARTH + "rm6", "southwest",
	});

	items = ({
  "walls",
"They are definitely becoming more solid, and less crumbly as you contintue "+
"along the passage.  What is causing this change, you do not yet know..",
  "rock",
"You cannot identify the type of rock that the walls are made of..",
      });

    ::reset(arg);
    RPR("/room/room");
  }
}
