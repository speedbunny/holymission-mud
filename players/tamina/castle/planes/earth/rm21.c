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
"    The path you take suddenly becomes very warm, as a blast\n"+
"    of hot air hits you in the face.  You guess from this, that\n"+
"    the source of heat is definitely coming from round this\n"+
"    tunnel...\n";

     	dest_dir = ({
      EARTH + "rm19", "south",
      EARTH + "rm22", "east",
	});
  ::reset(arg);
  RPR("room/room");
}
