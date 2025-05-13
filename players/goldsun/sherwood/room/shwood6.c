inherit "/room/room";
#include "../full_of_edge.h"
#include "items_edge.h"

reset(arg){
 if (!arg) {
 clone_list=({1,1,"rat","/players/goldsun/sherwood/monster/rat",0});
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=
   ("You are at the edge of the Sherwood forest. The forest looks very dense\n"
    +"and mystical; trees and bushes are everywhere. From time to time \n" 
    +"you can hear an animal sound echoing from the forest.\n"
     +"To the north you can see a steep hill covered with moss and\n"
                 +"small bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood10", "south",
           "/players/goldsun/sherwood/room/shwood14", "west",
           "/players/goldsun/sherwood/room/shwood5", "east"});
        
 items=({"soft moss","The moss is really very soft",
	 "green moss","The moss is nice green",
         "hill", "The hill is covered with moss and bushes. It is impossible"
                      +"to climb up\n"+
                 "because the hill is steep here"})+ITEMS;
  }
 ::reset();
}

init(){
 ::init();
add_action("climb2","climb");
add_action("shake","shake");
add_action("pass","pass");
add_action("light","light");
add_action("cut","cut");
add_action("dig","dig");
add_action("tear2","tear");
add_action("listen","listen");
add_action("cut","chop");
}
