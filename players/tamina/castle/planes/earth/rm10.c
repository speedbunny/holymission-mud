/*  room 10 */

inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (arg) return 0;

      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "In a tunnel";
	long_desc = 
"    This passage just seems to end at this point.\n"+
"    You round the small bend, and find yourself facing a blank\n"+
"    wall, immaculately carved, with hardly a blemish on the wall\n"+
"    at all.  You stand and marvel a while at the beauty of these\n"+
"    tunnels...But the darkness grips round your heart, and knocks\n"+
"    from the reverie.\n";

     	dest_dir = ({
      EARTH + "rm9", "northwest",
	});

	items = ({
  "walls",
"These have been carved so smoothly that the light you are holding "+
"reflects clearly from the surface.  It is so well-done that you feel "+
"kind of strange standing next to the walls",
  "wall",
"These have been carved so smoothly that the light you are holding "+
"reflects clearly from the surface.  It is so well-done that you feel "+
"kind of strange standing next to the walls",
     });

   ::reset(arg);
   RPR("room/room");
}
