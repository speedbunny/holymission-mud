 
inherit "room/room";
#include "../garden.h"
 
void reset(int arg) 
{
  if (!filter_live(TO))
      CM("lynx");

  if (arg) return;
  set_light(0);
  property = "no_teleport";
  short_desc = "In a dark forest";
  long_desc = BS(
     "You have now reached the northern end of the dark forest. "
   + "To the west and east the forest is dark and impenetrable. "
   + "To the north you can now see the contours of a big building "
   + "and it looks so devilish that you shiver and go cold inside just "
   + "thinking about it! Continue at your own risk. "
   + "There is a small path leading back to the south.");

  dest_dir = ({ ROOM+"/house1", "north", ROOM+"/forest6","south" });
  items = ({"forest","You can see a lot of 80 feet high spruces",
            "building",
            "If you look at that strange building you can imagine "+
            "that there are horrible\nthings going on."});
}
