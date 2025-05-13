inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){
  if (!arg){

  clone_list=({1,1,"wolf","/players/goldsun/sherwood/monster/wolf",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
 ("You are in the Sherwood forest. The dark forest is very huge.\n"
 +"The tangles of trees and bushes are everywhere around you.\n"
 +"The bushes looks very dangerous. They can hide whatever animals.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood28", "south",
           "/players/goldsun/sherwood/room/shwood33", "west",
           "/players/goldsun/sherwood/room/shwood26", "north"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("pass","pass");
add_action("tear","tear");
add_action("dig","dig");
add_action("listen","listen");
add_action("light","light");
add_action("shake","shakw");
add_action("cut","cut");
}
