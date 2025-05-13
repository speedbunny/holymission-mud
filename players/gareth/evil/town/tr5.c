#include "/players/gareth/define.h"
inherit "/room/room";

reset(arg) {
   if (!arg) {
   set_light(1);
   short_desc= "Town road";
   long_desc= "You stand at the far end of town. This seems to be the\n"+
              "sit of a great battle and it appears that the drow were\n"+
              "on the receiving end. The 'sky' is ablaze with from the\n"+ 
              "raging infernos that spew forth from the once great \n"+ 
              "buildings of Fantoma. Could it be that the drow have met\n"+
              "a great enemy??? The roads leading to the castles are\n"+
	      "littered with bodies and dried pools of blood. There's\n"+
	      "a sign to the side of the road.\n";
   items = ({
            "sign","A large sign made of bone, try reading it instead of looking at it",
            "blood","Red blood of drow and some green fuild - interesting",
            "buildings","Buildings that have been set ablaze by some attacker",
            "castles","The burning wrecks of the once great drow",
            "smoke","Thick smoke that comes from the burning castles",
            "road","Dirty road in the middle of town",
           });
   dest_dir =({
     ETOWN+"tr4","south",
     });
   
   }

}


