inherit "/room/room";
#include "../full.h"
#include "items.h"


reset(arg){
 if (!arg){
 clone_list=({1,1,"rarah","/players/goldsun/sherwood/monster/rarah",0});
 set_light(0);
 short_desc=("Rarah place");
 long_desc=
  ("You are edging through the dense bushes and grass. The trees are\n"
  +"very high and huge. This place looks like Rarah's favourite thicket.\n"
  +"You cannot see anything else because the forest is very dark.\n");


 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood29", "south",
           "/players/goldsun/sherwood/room/shwood34", "west",
           "/players/goldsun/sherwood/room/shwood27", "north",
           "/players/goldsun/sherwood/room/shwood20", "east"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("pass","pass");
add_action("dig","dig");
add_action("cut","chop");
add_action("light","light");
add_action("listen","listen");
add_action("cut","cut");
add_action("tear","tear");
add_action("shake","shake");
}
