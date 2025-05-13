 
inherit "room/room";
#include "../garden.h"
 
void reset(int arg) 
{
  if (filter_live(TO) < 1)
      CM("bat");

  if (arg) return;
  set_light(0);
  short_desc = "In a dark forest";
  no_castle_flag = 0;
  long_desc = BS(
    "You are standing in the northern part of the dark forest. "+
    "You see many tall spruce trees surrounding you. To the west and "+
    "east the forest is dark and impenetrable. There is a small "+
    "dirty path covered with foliage leading north and south.");

  dest_dir = ({ ROOM+"/forest9", "north", ROOM+"/forest5","south" });
  items = ({"forest","You can see a lot of 80 feet high spruces",
            "spruces","You can see a lot of 80 feet high spruces",
        });
}
