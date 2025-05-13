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
	short_desc = "Underground, the Plane of Earth";
	long_desc = 
"    You find yourself in what appears to be a hollowed-out earthen\n"+
"    tunnel, caved from tons of Earth.  And as you look at the walls,\n"+
"    you soon notice that the techiques are completely unfamiliar\n"+
"    to you.  The tunnel you are in seems to be devoid of any air\n"+
"    that you can breathe.  So it is not surprising to you that you\n"+
"    are not breathing!!  The tunnel you are in winds to the north\n"+
"    here, or returns back to the east.\n";

     	dest_dir = ({
      EARTH + "rm1", "east",
      EARTH + "rm3", "north",
	});

	items = ({
  "",
"",
  "",
"",
      });

    }
}
