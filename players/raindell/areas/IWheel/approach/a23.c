#include "/include/defs.h"
inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="On the river side of the rockslide"; 
  long_desc="\nThe southern canyon wall seems to break quite suddenly here, though you can't\n"
            "see down the ravine to the south due to a large pile of tumbled boulders\n"
            "lying in the line of sight. Despite the rockslide, the river flows calmly on\n"
            "its way as it curls around the bend and heads slightly downhill to the\n"
            "northwest again. While the plants grow adequately here, there seem to be\n"
	      "fewer of them.\n\n";           

  dest_dir=({"/players/raindell/areas/IWheel/approach/a24","northwest",
             "/players/raindell/areas/IWheel/approach/a22","northeast",
		});

  items=({"wall","Its solidity is broken briefly by a ravine that cuts to the south through the rock", 
          "ravine","It appears to head to the south, but you really can't see too much due to the boulders",
          "boulders","Though stacked high, it looks like you might be able to 'climb' over them if you were careful",
	    "rockslide","A large tumbled pile of boulders",
	    "river","It flows slightly downhill to the northwest as it rounds the bend",
	    "bend","The turning in the river seems to be almost marked by the rockslide",
	    "plants","They look quite normal and healthy",
	     	});

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

}

void init() {

   ::init();

   add_action("_climb","climb");
 }
     int _climb(string str) {
     if(str!="boulders") return 0;
     write("You carefully pick your way over the boulders.\n");
     MP("carefully over the boulders.#players/raindell/areas/IWheel/approach/a28.c");

   return 1;

   }

