inherit "/room/room";
#include "items.h"
#include "../climb.h"
#include "../cut.h"
#include "../shake.h"
#include "../pass.h"
#include "../light.h"
#include "../tear.h"
#include "../listen.h"

reset(arg){

 if (!arg){
 clone_list=({1,1,"bear","/players/goldsun/sherwood/monster/bear",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
  ("You are in the Sherwood forest. This place looks dangerous.\n" 
   +"The trees and bushes are everywhere and some of them are broken.\n"
  +"You can see the bears footprints on the ground.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood13", "south",
           "/players/goldsun/sherwood/room/shwood17", "west",
           "/players/goldsun/sherwood/room/shwood11", "north",
           "/players/goldsun/sherwood/room/shwood9", "east"});
        
 items=({"place","It looks like bears place",
	 "footprints","There are bears footprints",
	 "footprint","It is bear footprint",
         "bear footprint","A common bear footprint",
         "bears footprints","The footprints aim at huge bush",
	 "broken bush","The bush looks broken by a huge animal",
	 "broken bushes","The bushes are broken by a huge animal",
	 "broken tree","The tree is broken by a huge animal",
	 "broken trees","The trees are broken by a huge animal",
	 "bush","The bush is huge and dense.\n"
		     +"Several branches are broken",
	 "branch","A broken branch",
         "broken branch","a broken branch"})+ITEMS;
  }
 ::reset();
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

dig(str){
 if (str=="down"){
  write("You start to dig down.\n");
  write("\nOUPS\n\n");
  write("You fall through down.\n");
  TP->move_player("down#/players/goldsun/sherwood/room/dcave2");
  return 1;
 }
 else{
  write("Where do you want to dig ?\n");
  say(OPN+"looks around.\n");
  return 1;
  }
}
