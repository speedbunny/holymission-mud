inherit "/room/room";
#include "../cut.h"
#include "../tear2.h"
#include "../shake.h"
#include "../dig.h"
#include "../light.h"
#include "../pass.h"
#include "../listen.h"
#include "items_edge.h"

reset(arg){
 if (!arg){

clone_list=({1,1,"pheasant","/players/goldsun/sherwood/monster/peasant",0});
 set_light(1);
 short_desc=("The edge of Sherwood");
 long_desc=("You are at the edge of the Sherwood forest. The trees and bushes"
                 +" are\n"
           +"everywhere. From time to time you can hear an animal sound from"
                 +" the forest.\n"
           +"To the north and east you can see a steep hill covered by the"
                 +" moss and\n"
           +"small bushes.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood19", "south",
           "/players/goldsun/sherwood/room/shwood25", "west",
           "/players/goldsun/sherwood/room/shwood24", "northwest",
           "/players/goldsun/sherwood/room/shwood14", "southeast"});
        
 items=({"grass","The grass is waving in the wind",
	 "green moss","The moss is really green",
	 "soft moss","The moss is soft and green",
         "hill", "The hill is covered with moss and bushes. It is impossible"
                      +" to climb up\n"+
                 "because the hill is steep here"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("shake","shake");
add_action("listen","listen");
add_action("dig","dig");
add_action("cut","chop");
add_action("cut","cut");
add_action("light","light");
add_action("pass","pass");
add_action("tear2","tear");
}

climb(str){
   if (str=="tree" || str=="old tree" || str=="huge tree"){
    write("You don't think you could climb this tree.\n");
    say(OPN+" looks confused.\n");
   }
    else
   if (str=="hill" || str=="up" || str=="up hill" || str=="up the hill"){
   write("Uf.\n");
   write("Uf.\n");
   write("You climb up the hill.\n");
   this_player()->move_player("up the hill#/players/goldsun/sherwood/room/plain1");
    return 1;
   }
    else {
    write("What do you want to climb ?\n");
     say(OPN+" looks around.\n");
     }
 return 1;
}

