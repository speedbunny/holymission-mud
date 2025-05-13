inherit "/room/room";
#include "/obj/door.h"

object obj_1, obj_2;

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Passage");
 long_desc="You are in the small passage of the castle cellar. The passage\n"+
	   "continues to the west. Torches along the wall give off\n"+
           "a smoky odour.\n";
 
 MAKE_DOORS("/players/goldsun/nottingham/room/castle/cell1","south",
          "/players/goldsun/nottingham/room/castle/prison3","north","copper",
          "cell1_code",
          "An oak door.\n", 1,1,1);

 MAKE_DOORS("/players/goldsun/nottingham/room/castle/prison3","south",
          "/players/goldsun/nottingham/room/castle/cell2","north","copper",
          "cell2_code",
          "An oak door.\n", 1,1,1);

 smell="You smell torch smoke.";
 property=({"has_fire"});
 dest_dir=({"/players/goldsun/nottingham/room/castle/prison2","west"});

 items=({ "cellar" ,"Dump murky cellar of Nottingham castle",
	  "torches","They are attached to the wall",
	  "passage","A passage to the west"
	  
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

