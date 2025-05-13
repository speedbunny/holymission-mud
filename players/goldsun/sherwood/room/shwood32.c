inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){
 set_light(0);
 short_desc=("Sherwood");
 long_desc=("You are in the dark Sherwood forest. The trees and bushes are"
                 +" everywhere.\n"
           +"You can sense animals around yourself but you cannot see"
                 +" them.\n"
 +"Only grass is waving in the wind.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood33", "south",
           "/players/goldsun/sherwood/room/shwood36", "west",
           "/players/goldsun/sherwood/room/shwood31", "north",
           "/players/goldsun/sherwood/room/shwood26", "east"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 ::reset(arg);
}

init(){
 ::init();
add_action("climb","climb");
add_action("pass","pass");
add_action("light","light");
add_action("dig","dig");
add_action("shake","shake");
add_action("tear","tear");
add_action("cut","chop");
add_action("cut","cut");
add_action("listen","listen");
}

