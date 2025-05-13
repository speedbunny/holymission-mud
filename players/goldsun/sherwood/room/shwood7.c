inherit "/room/room";
#include "items.h"
#include "../full.h"

reset(arg){
 if (!arg){
 clone_list=({1,1,"foliage","/players/goldsun/sherwood/obj/foliage",0});
 if (arg) return;
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
  ("You are in the Sherwood forest. It is dark and dense here. \n"
  +"The old trees and dense bushes are everywhere. You cannot see\n"
  +"anything else. You can sense animals around you but\n"
  +"you cannot see them.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood8", "south",
           "/players/goldsun/sherwood/room/shwood10", "west",
           "/players/goldsun/sherwood/room/shwood5", "north",
           "/players/goldsun/sherwood/room/shwood3", "east"});
        
 items=({"grass","The grass is green. It looks very sharp",
	 "sharp grass","The grass is green. It would harm you if you tore it",
	 "green grass","The grass looks very sharp"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
 add_action("climb","climb");
 add_action("shake","shake");
 add_action("cut","chop");
 add_action("pass","pass");
 add_action("light","light");
 add_action("cut","cut");
 add_action("dig","dig");
 add_action("tear","tear");
 add_action("listen","listen");
 }
