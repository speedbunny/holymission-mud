inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
   1,1,"crayfish",im+"/crayfish",0
 });
 dest_dir=({ 
      ir+"/scoast3", "north",
	ir+"/river8", "east",
	ir+"/river6", "south",
	ir+"/scoast2", "west"
	   });
 }
 ::reset(arg);
}
