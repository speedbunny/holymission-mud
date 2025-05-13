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
"    The curving tunnel continues around in almost semi-circular \n"+
"    regularity, the only flaw being a small opening in the west\n"+
"    wall.\n";

     	dest_dir = ({
      EARTH + "rm11", "northeast",
      EARTH + "rm14", "south",
      EARTH + "rm13", "west",
	});

	items = ({
  "opening",
"It leads to what appears to be a smaller chamber",
      });

  ::reset(arg);
  RPR("room/room");
}
