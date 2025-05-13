 
inherit "room/room";
#include "../garden.h"
 
void reset(int arg) 
{
  if (arg) return;
  set_light(0);
  short_desc = "In a dark forest";
  no_castle_flag = 0;
  long_desc = BS(
     "You are standing in the northern part of the dark forest. "
   + "You see many large spruce trees around you. A narrow path "
   + "leads to the southeast, southwest, and south. It also leads "
    + "further north where you see a strange light coming from an "
   + "odd looking building. If I were you, I would leave this "
   + "evil looking place.");

  dest_dir = ({ ROOM+"/forest2", "southeast",
		ROOM+"/forest3","southwest",
		ROOM+"/forest4", "south",
		ROOM+"/forest6", "north", });
  items = ({"trees", "Nearly 80 feet high, you can barely see the top",
            "building",
            "You see the shape of what you think is an old house."});
}
