inherit "/room/room";
#include "/obj/door.h"


reset(arg){
 if (!arg){
 clone_list=({1,1,"guard","players/goldsun/white_tower/monster/monk1",0});
 set_light(1);
 short_desc=("Prison cell");
 long_desc="You are in the castle prison. It is a small room with bench,\n"+
	   "straw and one torch on the wall.\n";
 
 smell="You smell torch smoke.";

 property=({"has_fire"});
 no_obvious_msg="";
 items=({ "bench","A wooden bench with straw on it",
	  "straw","The straw looks rotten",
          "cell" ,"Dump murky cell of Nottingham castle",
	  "torch","It is attached to the wall"
	  
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

