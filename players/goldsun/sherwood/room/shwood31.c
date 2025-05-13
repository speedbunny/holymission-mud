inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){

  if (!arg){

 clone_list=({1,1,"owl","/players/goldsun/sherwood/monster/owl",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
 ("You are in the dark forest. The tangle of dense bushes and huge trees\n"
+"is grown up everywhere. You cannot see anything else.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood32", "south",
           "/players/goldsun/sherwood/room/shwood35", "west",
           "/players/goldsun/sherwood/room/shwood30", "north",
           "/players/goldsun/sherwood/room/shwood25", "east"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
add_action("listen","listen");
add_action("cut","cut");
add_action("cut","chop");
add_action("climb","climb");
add_action("dig","dig");
add_action("light","light");
add_action("shake","shake");
add_action("tear","tear");
add_action("pass","pass");
}

