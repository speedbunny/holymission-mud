inherit "/room/room";
#include "items.h"
#include "../tear.h"
#include "../light.h"
#include "../listen.h"

reset(arg){
 ::reset(arg);
 set_light(1);
 short_desc=("The oak tree");
 long_desc=("You are on the oak tree.\n"
	    +"The green leaves are waving in the wind.\n");
 smell="You smell damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/sherwood/room/Robin","down"});
 items=({"tree","This tree is mystical oak with a crack",
	 "crack","A dark crack in the tree trunk",
         "hole","A dark crack in the tree trunk",
	 "leaves","The green leaves",
	 "leaf","An oak leaf",
	 "wind","How could you see that ?",
	 "trunk","A tree trunk with a crack in it",
         "forest","The forest looks strange"});
 }

init(){
 ::init();
 add_action("enter","enter");
 add_action("tear","tear");
 add_action("listen","listen");
 add_action("climb","climb");
 add_action("light","light");
 add_action("shake","shake");
 }

shake(str){
 if (str=="tree" || str=="oak" || str=="oak tree"){
  write("You shake this tree but nothing happend.\n");
  say(OPN+" shakes the tree but nothing happend.\n");
  return 1;
  }
}
climb(str){
 if (str=="tree" || str=="oak" || str=="oak tree"){
  write("You don't think you could climb up this tree.\n");
  say(OPN+" tries to climb up this tree.\n");
  return 1;
 }
}

enter(str){
 if (str=="crack" || str=="tree" || str=="oak" || str=="oak tree"
    	|| str=="hole"){
  if (this_player()->query_size()>1){
   write("The crack is too small for you.\n");
   say(this_player()->query_name()+" tries to enter a crack.\n");
   }
  else{
   write("You enter the crack.\n");
   this_player()->move_player("enters the crack#/players/goldsun/sherwood/room/tree2");
   }
  return 1;
 }
}
