
inherit "room/room";
#include "../tree.h"


void reset(int arg) 
{
  if (filter_live(this_object()) < 4)
      random_clone();

if (arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = BS(
       "You are climbing higher up the apple-tree. "+
       "The branches are moving in the wind and "+
       "you feel the smell of fresh apples in "+
       "your nose.");
  items = ({ "branch","A long brown branch",
    	"branches","Long brown branches" });
  dest_dir = ({ PATH+"t20","south",
    		PATH+"t29","up",
    		PATH+"t5","down",
    		PATH+"t34","north",
    		PATH+"t23","west",
    		PATH+"t26","east" });
  }
