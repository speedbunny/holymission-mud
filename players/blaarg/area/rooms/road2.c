#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	::reset(arg);
	if(arg) return;
       set_light(1);
	short_desc="North Road",
       long_desc=
		"This is the road leading north into the village.\n"+
		"The forest looks a little clearer on the west side.\n";
	items=({
		"road", "The dirt road is well packed",
		"forest", "The forest is too thick to see through, but "+
			   "you might be able to pass through to the west\n",
		"village", "The small village starts to the north, "+
			    "after the forest ends.\n",
        	});
	dest_dir=({
	AROOMS+"road1", "south",
	AROOMS+"road3","north",
		 });
       property = ({
                     "no_steal",
                    });
       smell = "The scent of pines is almost overwhelming.";
}

init()
{
  ::init();
  add_action("pass", "pass");
}

pass(str) {
	if( str=="forest" || str=="west" || str=="western forest"){
	   write("You pass into the forest.\n");
	  TP->move_player("in the forest#"+AROOMS+"forest1.c");
	   return 1;
	   }
	else {
	   write("What are you trying to pass?\n");
	     }
	return 1;
    }

