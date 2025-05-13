#define TP this_player()
#define TO this_object()

inherit "room/room";
#include "../tree.h"
 object ob;

void reset(int arg) 
{

  if (!ob)
      move_object(ob=clone_object(MONST+"eagle"), TO);

if (arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = BS(
    	"You have now reached the top of the tree. "+
 	"You can see the whole landscape. "+
    	"This is a place where the eagles prefer to "+
    	"build their nests. You can feel the sweet "+
    	"smell of fresh apples in your nose.");
  items = ({ "landscape","You see the city the mountains and the beautiful sea",
    	"branch","A long brown branch",
    	"branches","Long brown branches" });
  dest_dir = ({ PATH+"t29","down" });
  smell = "You smell the sweet scent of apples everywhere.";
}

