inherit "/room/room";
#include "/players/patience/GenObj/move_blocked.h"

reset(arg){
 if (!arg){
  clone_list=({1,1,"dragon","/players/goldsun/sherwood/monster/dragon",0,
  	       2,1,"handle","/players/goldsun/obj/nothung_handle",0});
 set_light(0);
 no_castle_flag=1;
 short_desc=("A dark cave");
 long_desc=("You are in the dark cave.\n");
 smell="You smell damp air.";
 dest_dir=({"/players/goldsun/sherwood/room/hill1","out"});
 items=({"cave","The cave is damp and dark",
	 "dark cave","The cave is damp and dark",
	 "damp cave","The cave is damp and dark"});
  }
 ::reset();
 replace_program("/room/room");
 }
