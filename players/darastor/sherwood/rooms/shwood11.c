inherit "/room/room";
#include "items.h"
#include "../shake.h"
#include "../pass.h"
#include "../light.h"
#include "../cut.h"
#include "../dig.h"
#include "../tear.h"
#include "../listen.h"

void reset(int arg){

 if (!arg){
 clone_list=({1,1,"wasp","players/goldsun/sherwood/monster/wasp",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
   ("You are in the Sherwood forest. The forest is dark. You cannot see\n"
   +"more than huge trees and dense bushes around you. One of the trees\n"+
    "has low branches. You haven't good feeling here.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood10","north",
           "/players/goldsun/sherwood/room/shwood16", "west",
           "/players/goldsun/sherwood/room/shwood12", "south",
           "/players/goldsun/sherwood/room/shwood8",  "east"});
        
 items=({"grass","The grass is green",
	 "green grass","The grass is green"})+ITEMS;
 }
 ::reset(arg);
}


void init(){
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

int climb(string str){
 if (str=="tree" || str=="branch" || str=="branches"){
   write("You climb up the tree.\n");
   this_player()->move_player("up#players/goldsun/sherwood/room/tree3");
   return 1;
 }
 notify_fail("Climb what?\n");
}
