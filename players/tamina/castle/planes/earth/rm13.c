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
"    On taking the turn-off, you see this is no more than a smoothly\n"+
"    carved room, with flawless, featureless walls.\n";

     	dest_dir = ({
      EARTH + "rm12", "east",
	});

	items = ({
  "walls",
"They glow so much with eerie light that the walls look now as if they "+
"have been carved out of ivory",
      });

  ::reset(arg);
  RPR("room/room");
}
