
inherit "room/room";
#include "../tree.h"

int reset(void arg) 
{
  if (filter_live(this_object()) < 4)
      random_clone();

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = BS(
    "You are climbing on a big apple-tree. The branches look as if they "+
    "have been pruned here recently. The branch is also much to sturdy "+
    "to fall from.");
  items = ({ "branch","A long brown branch",
    	"branches","Long brown branches" });
  dest_dir = ({ PATH+"t4","north" });
}
