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
"    The curving tunnel leads you to a sort of junction.\n"+
"    There is a leading-off tunnel behind you to the east,\n"+
"    or you can coninue along with what appears to be the main\n"+
"    tunnel.\n";

     	dest_dir = ({
      EARTH + "rm16", "northeast",
      EARTH + "rm19", "east",
      EARTH + "rm18", "west",
	});

	items = ({
  "tunnel",
"It continues to curve around with a smooth radius",
      });

  ::reset(arg);
  RPR("room/room");
}
