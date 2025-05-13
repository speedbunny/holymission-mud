inherit "/room/room";
#include "items_edge.h"
#include "../full_of_edge.h"

reset(arg){
 
 if (!arg){
 clone_list=({1,1,"trunk","/players/goldsun/sherwood/obj/trunk",0});
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=("You are at the edge of Sherwood forest. The trees and bushes"
                 +" are\n"
           +"everywhere. From time to time you can hear an animal sound from"
                 +" the forest.\n"
           +"To the north and east you can see a steep hill covered with"
              +" moss and\n"
           +"small bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood7", "south",
           "/players/goldsun/sherwood/room/shwood6", "west"});
        
 items=({"grass","The grass is waving in the wind",
	 "green moss","The moss is green and soft",
	 "soft moss","The moss is soft and green",
         "hill", "The hill is covered with moss and bushes"})+ITEMS;
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
add_action("cut","chop");
add_action("dig","dig");
add_action("tear2","tear");
add_action("listen","listen");
} 
