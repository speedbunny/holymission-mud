
inherit "room/room";
#include "../tree.h"

void reset(int arg)
{
  if (filter_live(this_object()) < 4)
  {
    random_clone(); 
    random_clone(); 
  }
  set_light(1);
  short_desc = "In an apple tree";
  long_desc = BS(
    	"You are climbing higher up the apple-tree. "+
	"It looks like the tree has been pruned here recently, "+
	"making this area a lot sturdier.");
  items = ({ "branch","A long brown branch",
    	"branches","Long brown branches" });
  dest_dir = ({ PATH+"t25","southeast",
    		PATH+"t27","northeast",
    		PATH+"t21","west" });
}

