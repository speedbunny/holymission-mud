inherit "/room/room";
#include "items_edge.h"
#include "../full_of_edge.h"

reset(arg){

 if (!arg){
 clone_list=({1,1,"blue bush","/players/goldsun/sherwood/obj/bush",0});
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=
 ("You are at the edge of the Sherwood forest. The trees and bushes are\n"
   +"everywhere. From time to time you can hear an animal sound from"
                 +" the forest.\n"
  +"To the south you can see a steep hill covered by the moss and"
                 +" small bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood22", "west",
           "/players/goldsun/sherwood/room/shwood17", "north",
           "/players/goldsun/sherwood/room/shwood13", "east"});
        
 items=({
	 "edge","You can seen huge trees and dense bushes",
	 "green moss","The moss is green",
	 "soft moss","The moss is soft and green",
         "hill", "The hill is covered with moss and bushes. It is impossible"
                      +" to climb up\n"+
                 "because the hill is steep here"})+ITEMS;
 }
 ::reset(arg);

}
init(){
 ::init();

add_action("climb2","climb");
add_action("listen","listen");
add_action("tear2","tear");
add_action("cut","cut");
add_action("cut","chop");
add_action("dig","dig");
add_action("light","light");
add_action("pass","pass");
add_action("shake","shake");
 }

