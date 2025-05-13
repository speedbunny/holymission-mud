
inherit "room/room";
#include "../tree.h"

void reset(int arg) 
{
  if (filter_live(this_object()) < 4)
      random_clone();

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = BS(
    "You have nearly reached the top of the tree. "+
    "The branches are moving stronger, that you "+
    "nearly fall down.");
  items = ({ "branch","A long brown branch",
     	"branches","Long brown branches" });
  dest_dir = ({ PATH+"t29","south" });
}
