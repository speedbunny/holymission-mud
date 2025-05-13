inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){
 if (!arg){
 clone_list=({1,4,"bunny","/players/goldsun/sherwood/monster/bunny",0});
 set_light(1);
 short_desc=("Sherwood");
 long_desc=("You are in Sherwood forest. Trees and bushes are"
                 +" everywhere.\n"
	    +"Sometimes you can hear animal sounds from the forest."
	       +" There is\n"
	   +"tall grass around you.\n");
 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood2", "south",
           "/players/goldsun/sherwood/room/shwood7", "west"});
        
 items=({"tall grass","The grass is tall and green. Bunnies like this\n"
			+"grass very much",
	 "grass","The grass is tall and green. It is good food for bunnies",
	 "green grass","The grass is tall and green"})+ITEMS;
 }
 ::reset();
}
init(){
 ::init();
 add_action("tear","tear");
 add_action("light","light");
 add_action("cut","cut");
 add_action("cut","chop");
 add_action("dig","dig");
 add_action("listen","listen");
 add_action("shake","shake");
 add_action("climb","climb");
 add_action("pass","pass");
}
