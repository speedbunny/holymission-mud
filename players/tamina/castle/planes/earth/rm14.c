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
"    The curving tunnel continues around here, where you can merely\n"+
"    go with the pasage, or return the way you came.  The walls \n"+
"    almost take on the appearance of glass, they are so smooth...\n";

     	dest_dir = ({
      EARTH + "rm12", "north",
      EARTH + "rm15", "southeast",
        });

	items = ({
  "walls",
"You can almost see your reflection in the walls, they are so smooth"
      });

  ::reset(arg);
  RPR("room/room");
}
