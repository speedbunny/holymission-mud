inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){
 if (!arg) { 
 clone_list=({ 1, 3, "highwayman", "players/goldsun/sherwood/monster/hwman",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=("You are in the Sherwood forest. The trees and bushes are"
                 +" everywhere.\n"
           +"You feel many animals around yourself but you cannot see"
                 +" them.\n");
 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood17", "south",
           "/players/goldsun/sherwood/room/shwood20", "west",
           "/players/goldsun/sherwood/room/shwood15", "north",
           "/players/goldsun/sherwood/room/shwood11", "east"});
        
 items=({
         "grass","The grass is waving in the wind"})+ITEMS;
  }
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
