inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,2,"eel",im+"/eel",0
 });
 dest_dir=({ 
      ir+"/river7", "north",
      ir+"/river2", "northeast",
      ir+"/scoast9", "south",
	ir+"/river6", "northwest"
	   });
 }
 ::reset(arg);
}
