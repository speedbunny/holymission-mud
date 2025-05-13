inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (!arg)
    {
      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "In a tunnel";
	long_desc = 
"    The caved-out passage continues onward, in the seeming complete\n"+
"    darkness.  There is very little in these tunnels, so that they \n"+
"    all seem rather similar indeed.\n";

     	dest_dir = ({
      EARTH + "rm5", "south",
      EARTH + "rm3", "east",
	});

	items = ({
  "",
"",
  "",
"",
      });

    }
}
