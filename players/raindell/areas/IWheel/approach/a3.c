#include "/include/defs.h"
inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="A washed-out flagstone path"; 
  long_desc="\nYou are standing on the remains of a washed-out flagstone\n"
            "pathway on the edge of a lazily flowing river. The water's edge\n"
            "is lined with trees near the bushes, but ascends into steep, rocky\n" 
            "walls after a few feet. There seems to be some vegitation near the\n"
            "water, and the sounds of a few scattered birds echo on the canyon's\n"
            "walls. While the path vanishes into the river, the water itself is\n"
		"only about knee-deep, and flows from the northwest to the southeast.\n\n";

  dest_dir=({"/players/raindell/areas/IWheel/approach/a4","northwest",      
		 "/players/raindell/areas/IWheel/approach/a9","southeast",
           });

  items=({"pathway","While visible now, the flagstones are worn from time, and have scattered as the river rose to meet them", 
          "river","The clear water flows lazily to the southeast",
          "water","You can see the scattered flagstones through the water. Some even protrude above the surface",
          "trees","They're quite healthy and green",
          "walls","Jagged rock walls rise above the water, dotted with tiny holes",
          "vegitation","The waterplants are plentiful near the shore",
	    "flagstones","The remnants of the path are scattered over the riverbed",
	    "holes","The birdsong seems to come from these",
	    "bushes","They're rather cramped and scratchy, but look passable if you 'part' them",
	     });

clone_list=({1,1,"bluebird","/players/raindell/areas/IWheel/approach/critters/bluebird",0
              });

::reset(arg);

}
void init() {

   ::init();

   add_action("_part","part");
 }
     int _part(string str) {
     if(str!="bushes") return 0;
     write("You push your way through the bushes.\n");
     MP("into the bushes carefully.#players/raindell/areas/IWheel/approach/a2.c");

   return 1;

   }









