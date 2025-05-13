inherit "/room/room";
#include "items.h"
#include "../full.h"

reset(arg){

 set_light(0);
 short_desc=("Sherwood");
 long_desc=
 ("You are in the Sherwood forest. The forest is dark and dense.\n"
  +"The trees and shadowy bushes are everywhere. \n"
 +"You can sense animals around yourself but you cannot see"
                 +" them.\n");
 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood23", "north",
           "/players/goldsun/sherwood/room/shwood26", "west",
           "/players/goldsun/sherwood/room/shwood14", "east"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 ::reset(arg);
}

init(){
 ::init();
add_action("climb","climb");
add_action("listen","listen");
add_action("dig","dig");
add_action("cut","cut");
add_action("light","light");
add_action("shake","shake");
add_action("tear","tear");
add_action("pass","pass");
}


