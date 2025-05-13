inherit "/room/room";
#include "items_edge.h"
#include "../full_of_edge.h"

reset(arg){
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=
("You are at the edge of the Sherwood forest. The forest looks very dense\n"
+"and dark. The trees and bushes are everywhere. From time to time\n" 
+"you can hear an animal sound from the forest. To the north and east\n"
+"you can see a steep hill covered by the moss and small bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood25", "south",
           "/players/goldsun/sherwood/room/shwood30", "west",
           "/players/goldsun/sherwood/room/shwood23", "southeast"});
        
 items=({
	 "green moss","The moss is really green",
	 "soft moss","The moss is really soft",
	 "grass","The grass is waving in the wind",
         "hill", "The hill is covered with moss and bushes. It is impossible"
                      +" to climb up\n"+
                 "because the hill is steep here"})+ITEMS;
 ::reset(arg);

}

init(){
 ::init();
add_action("climb2","climb");
add_action("tear2","tear");
add_action("pass","pass");
add_action("cut","cut");
add_action("cut","chop");
add_action("dig","dig");
add_action("listen","listen");
add_action("shake","shake");
add_action("light","light");
}
