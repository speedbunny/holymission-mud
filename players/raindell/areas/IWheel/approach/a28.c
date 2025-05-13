#include "/include/defs.h"

inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The blocked path"; 
  long_desc="\nWhere a pathway used to extend to the northwest, the remains of a good\n"
            "sized rockslide now rest. Many of the boulders have either tumbled one way\n"
            "or another, but enough remain where they fell to impede any progress. A\n"
            "broken dirt path extends to the southeast through the canyon, and you can\n"
	      "hear the sounds of flowing water beyond the boulders\n\n";
            
  dest_dir=({"/players/raindell/areas/IWheel/approach/a29","southeast",
          	});

  items=({"boulders","Though they block the way, it looks like you might be able to 'climb' them to proceed", 
          "rockslide","This collection of stones and boulders tumbled from the walls above a long time ago",
          "path","Partly overgrown and dirty, you can see an occasional piece of broken flagstone through it all",
	    "canyon","The walls of rock aren't that high here",
	    "flagstone","Shattered and half buried, you can barely see it at all",
	    "walls","They're quite rocky and jagged, not recommended for climbing",
	     	});
}

void init() {

   ::init();

   add_action("_climb","climb");
 }
     int _climb(string str) {
     if(str!="boulders") return 0;
     write("You carefully pick your way over the boulders.\n");
     MP("carefully over the boulders.#players/raindell/areas/IWheel/approach/a23.c");

   return 1;

   }

