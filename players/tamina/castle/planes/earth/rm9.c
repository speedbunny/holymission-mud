/*  room 9 */

inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (arg) return;

      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "In a tunnel";
	long_desc = 
"    You are in one of the minor branches of the tunnels.\n"+
"    This well-caved passageway seems to continue along for a \n"+
"    small distance to the south, and then binds round a slight\n"+
"    corner.\n";

     	dest_dir = ({
      EARTH + "rm7", "north",
      EARTH + "rm10", "southeast",
	});

    ::reset(arg);
    RPR("room/room");
}
