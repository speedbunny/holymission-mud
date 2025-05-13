#define TP this_player()
#define TO this_object()

inherit "room/room";
#include "../tree.h"

void reset(int arg) 
{
  if (filter_live(this_object()) < 4)
      random_clone();

if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = BS(
    "You are climbing on a big apple-tree. "+
    "The branches are moving in the wind and "+
    "you have the good smell of fresh apples in "+
    "your nose.");
  items = ({ "branch","A long brown branch",
    	"branches","Long brown branches" });
  dest_dir = ({ PATH+"t13","southwest" });
  }
