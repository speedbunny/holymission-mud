#include "/players/gareth/define.h"
inherit "/room/room";

reset(arg) {
   if (!arg) {
   set_light(1);
   short_desc= "Town road";
   long_desc= "You wander more down the road. All the evil residents\n"+
              "stare at you with hate and malice. You hear chanting\n"+
              "from the east, from a building that appears to be some\n"+ 
              "sort of church. There seems to be busy activity to the\n"+ 
              "west. Smoke pours out from a foul looking shack, that\n"+
              "is decorated with the bones of a humanoid.           \n";
   items = ({
            "church","An evil looking place where the chanting comes from",
            "bones","The bones of a humanoid - they are white",
            "shack","A sturdy looking shack where people run in and out",
            "residents","Drow that look at you with hate and anger",
            "smoke","Thick smoke that comes from the shack",
            "road","Dirty road in the middle of town",
           });
   dest_dir =({
     ETOWN+"tr4","north",
     ETOWN+"temple","east",
     ETOWN+"weaponry","west",
     ETOWN+"tr2","south",
     });
   
   }

}


