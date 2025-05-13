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
"    You look around, and find yourself in a blindingly bright\n"+
"    room.  The walls seem to be so smoothly polished that they \n"+
"    reflect your image perfectly.  The tunnel here is quite \n"+
"    circular, and curves away from you.\n";

     	dest_dir = ({
      EARTH + "rm17", "southeast",
	});

	items = ({
  "walls",
"As you look at the wall, you can see yourself staring back at you "+
"in the tunnel...It is quite startling at first..",
      });

  ::reset(arg);
  RPR("room/room");
}
