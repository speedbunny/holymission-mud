 
inherit "room/room";
#include "../garden.h"
 
void reset(int arg) 
{
  if (filter_live(TO) < 1)
      CM("worm");

  if (arg) return;
  set_light(1);
  short_desc = "In a dark forest";
  long_desc = BS(
    "You are standing in front of a big, dark forest. "+
    "It's so dark here that you can hardly see anything. "+
   "You faintly see the tops of the spruce trees in "+
    "front of you and some thick bushes to the east and west.");

  dest_dir = ({ ROOM+"/path2", "south",
		ROOM+"/forest2", "northeast",
  "/players/whisky/meadow/room/m1", "east",
		ROOM+"/forest4", "north",
		ROOM+"/forest3", "northwest", });
  items = ({"bushes","They come to your waist and hide small animals",
            "trees","They are 60 feet high with large cones hanging down"});

}
