inherit "/room/room";
#include "../full.h"
#include "items.h"


reset(arg){

  if (!arg){

 clone_list=({1,1,"lynx","/players/goldsun/sherwood/monster/rys",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
 ("You are in the dark Sherwood forest. The bushes are very dense and\n"
+"can hide whatever animals. You can sense danger here.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood34", "south",
           "/players/goldsun/sherwood/room/shwood37", "west",
           "/players/goldsun/sherwood/room/shwood32", "north",
           "/players/goldsun/sherwood/room/shwood27", "east"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("cut","chop");
add_action("pass","pass");
add_action("listen","listen");
add_action("light","light");
add_action("shake","shake");
add_action("cut","cut");
add_action("dig","dig");
add_action("tear","tear");
}

