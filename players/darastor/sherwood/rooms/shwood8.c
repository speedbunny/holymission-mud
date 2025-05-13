inherit "/room/room";
#include "items.h"
#include "../full.h"
reset(arg){
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
   ("You are in the Sherwood forest. The forest is dark. You cannot see \n"
   +"anything else. The huge trees and dense bushes are everywhere.\n"
   +"You can sense animals around you but you cannot see them.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood9", "south",
           "/players/goldsun/sherwood/room/shwood11", "west",
           "/players/goldsun/sherwood/room/shwood7", "north",
           "/players/goldsun/sherwood/room/shwood2", "east"});
        
 items=({"grass","The grass is green",
	 "green grass","The grass is green"})+ITEMS;
 ::reset(arg);
}


init(){
 ::init();
 add_action("climb","climb");
 add_action("shake","shake");
 add_action("pass","pass");
 add_action("light","light");
 add_action("cut","cut");
 add_action("cut","chop");
 add_action("dig","dig");
 add_action("tear","tear");
 add_action("listen","listen");
}
