inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Knockaine Woods";
  long_desc = 
        "You are in the vast and magical Knockaine Woods, which is one "+
	"of the fairylands.  There are large willow trees growing all around you.  "+
	"Around the base of each tree, there are several "+
	"mugworts, moonworts, and mandrakes sprouting up in their own glory.  "+
        "The branches of the trees sweep down, giving the woods a curtained "+
	"sheltering atmosphere.  Lilies "+
	"of the valley are growing in patches all along the ground.  To the south is "+
	"the banks of a water source.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"wood/wood19", "north",
        FAIRY+"bank/bank44", "south",
        FAIRY+"wood/wood7", "east",
        FAIRY+"wood/wood5", "west",
  });
  items=({
        "fairylands", "The lands of the fairies",
        "woods", "The Knockaine Woods",
        "mandrake", "Plants growing to honor the moon goddess",
        "mugwort", "Plants growing to honor the moon goddess",
        "moonwort", "Plants growing to honor the moon goddess",
        "branches", "Branches fromt he willow trees sweeping down",
        "tree", "Large willow tree with swooping branches",
        "trees", "Large willow trees with swooping branches",
        "willow", "Large willow trees with swooping branches",
	"ground", "There are patches of lilies of the valley growing here",
	"lillies", "Lilies of the valley",
	"patches", "Lilies of the valley",
	"base", "Around it are mugworts, moonworts, and mandrakes",
        "banks", "The bank of the water",
        "you", "You cannot see yourself",
        "banks", "The banks of a water source",
        "water", "Silver water",
        "source", "Silver water",
  });
  clone_list=({
        1, 2, "fendeoree", FAIRY+"npc/fend", 0,
  });
  ::reset();
  replace_program("room/room");
}
