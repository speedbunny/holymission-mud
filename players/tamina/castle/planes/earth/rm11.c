inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (arg) return 0;

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "";
	long_desc = 
"    You continue along what appears to be the main corridor carved\n"+
"    out down here.  The walls are definitely changing substance as \n"+
"    you continue walking round the curving corridor...\n";

     	dest_dir = ({
      EARTH + "rm12", "southwest",
      EARTH + "rm7", "east",
	});

	items = ({
  "walls",
"As you look in awe at the glowing walls, you see that they are starting "+
"to become increasingly smoother and seem to radiate their own light",
  "corridor",
"It is in what appears to be the most perfect arc that you have seen before",
      });

  ::reset(arg);
  RPR("room/room");
}
