#include "/players/gareth/define.h"
inherit "/room/room";

reset(arg) {
   if (!arg) {
   set_light(1);
   short_desc= "Town road";
   long_desc= "You are in the heart of town. The towns folk look\n"+
              "at you with suspicion and disgust as you pass them\n"+
              "by. There is a increasing amount of darkness and death\n"+ 
              "as you head further down the road. To the east there\n"+ 
              "seems to be a building of some importance to the locals.\n"+
              "There also seems to be alot of warrior type drow entering\n"+
	      "the building to the west. There's a sign made of pure bone.\n";
   items = ({
            "sign","A large sign made of bone, try reading it instead of looking at it",
            "bone","The bones of a humanoid - they are white",
            "builing","A building that you might want to visit",
            "folk","Drow that look at you with hate and anger",
            "smoke","Thick smoke that comes from the shack",
            "road","Dirty road in the middle of town",
           });
   dest_dir =({
     ETOWN+"tr5","north",
     ETOWN+"shop","east",
     ETOWN+"armoury","west",
     ETOWN+"tr3","south",
     });
   
   }

}


