inherit "/room/room";
#include "items_edge.h"
#include "../full_of_edge.h"

reset(arg){

if (!arg){
  clone_list=({1,1,"well","/players/goldsun/sherwood/obj/well",0});
  set_light(1);
  short_desc=("The edge of Sherwood");
  long_desc=
   ("You are at the edge of the Sherwood forest. The forest looks mystical\n"
   +"and strange. The trees and bushes are everywhere. From time to time\n"
   +"you can hear an animal sound from the forest. To the south\n"
   +"you can see a steep hill covered with moss and small bushes.\n");

  smell="You smell common damp forest air.";
  dest_dir=({"/players/goldsun/sherwood/room/shwood8", "north",
            "/players/goldsun/sherwood/room/shwood12", "west",
            "/players/goldsun/sherwood/room/shwood4", "east"});
         
  items=({"green moss","The moss is green and soft",
	  "soft moss","The moss is pleasantly soft",
	  "green grass","The grass is green",
	  "water","The water should be in the well",
          "hill", "The hill is covered with moss and bushes. It is impossible"
                       +" to climb up\n"+
                  "because the hill is steep here"})+ITEMS;
     }
    ::reset();
   }

init(){
 ::init();
add_action("dig","dig");
add_action("light","light");
add_action("tear2","tear");
add_action("pass","pass");
add_action("listen","listen");
add_action("cut","cut");
add_action("cut","chop");
add_action("shake","shake");
add_action("climb2","climb");
}
