inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (arg) return 0;

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(1);
	short_desc = "The Forge";
	long_desc = 
"    The heat here is so powerful that it courses through your body\n"+
"    in surges of skin-tingling pulses.  In front of you is a pool of\n"+
"    bubbling lava.  Into this pool falls a steady flow of red molten\n"+
"    rock splashing melting stone around the room.  Just beside you is\n"+
"    a tiny, but apparently quite deep, basin of clear water, which\n"+
"    looks quite unaffected by the intense heat...\n";

     	dest_dir = ({
      EARTH + "rm22", "northwest",
	});

	items = ({
  "pool of lava",
"Forge",
  "pool",
"Forge",
  "basin",
"for cooling",
  "stone",
"is running - melted",
  "water",
"cool and clear",
  "rock",
"melted",
      });

  ::reset(arg);
  RPR("room/room");
}
