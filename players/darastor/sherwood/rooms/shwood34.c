inherit "/room/room";
#include "../full_of_edge.h"
#include "items_edge.h"

reset(arg){
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=("You are at the edge of the Sherwood forest. The trees and bushes"
                 +" are\n"
           +"everywhere. From time to time you can hear an animal sound from"
                 +" the forest.\n"
           +"To the south and west you can see a steep hill covered with"
                 +" moss and\n"
           +"bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood33", "north",
           "/players/goldsun/sherwood/room/shwood28", "east",
           "/players/goldsun/sherwood/room/shwood29", "southeast",
           "/players/goldsun/sherwood/room/shwood37", "northwest"});
        
 items=({
	 "grass","The grass is waving in the wind",
	 "green moss","The moss is really green",
	 "soft moss","The moss is green and soft",
         "hill", "The hill is covered with moss and bushes. It is impossible"
                      +" to climb up\n"+
                 "because the hill is steep here"})+ITEMS;
 ::reset(arg);

}

init(){
 ::init();
add_action("climb2","climb");
add_action("tear2","tear");
add_action("dig","dig");
add_action("cut","chop");
add_action("listen","listen");
add_action("light","light");
add_action("cut","cut");
add_action("pass","pass");
add_action("shake","shake");
}

