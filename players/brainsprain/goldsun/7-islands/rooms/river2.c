inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
   1,3,"beaver",im+"/beaver",0});
 dest_dir=({ 
      ir+"/river3", "north",
      ir+"/scoast6", "northeast",
	ir+"/river1", "southwest"
	   });
 }
 ::reset(arg);
}
