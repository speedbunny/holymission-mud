inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
   1,2,"trout",im+"/trout",0,
   2,1,"crayfish",im+"/crayfish",0
 });
 dest_dir=({ 
      ir+"/scoast4", "north",
	ir+"/scoast5", "east",
	ir+"/river8", "south",
	ir+"/scoast3", "west"
	   });
 }
 ::reset(arg);
}
