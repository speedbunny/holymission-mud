inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){
 if (!arg){
 clone_list=({1,4,"chipmunk","/players/goldsun/sherwood/monster/chipmunk",0});
 set_light(1);
 short_desc=("Sherwood");
 long_desc=("You are in Sherwood forest.\n"
	   +"There are huge trees and dense bushes around you.\n"
	    +"The grass grows high in some places.\n"
	    +"This place looks very sunny.\n");
	   
 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood2", "north",
           "/players/goldsun/sherwood/room/shwood9", "west"});
        
 items=({"sun","You feel quite comfortable",
	 "grass","It is common grass",
 	 "forest","The forest looks strange"
         	  +"You have never seen a forest like this before"})+ITEMS;
  }
 ::reset();
}
init(){
 ::init();
 add_action("tear","tear");
 add_action("climb","climb");
 add_action("cut","chop");
 add_action("pass","pass");
 add_action("light","light");
 add_action("shake","shake");
 add_action("dig","dig");
 add_action("cut","cut");
 add_action("listen","listen");
}
