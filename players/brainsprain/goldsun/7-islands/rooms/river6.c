inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
   1,2,"beaver",im+"/beaver",0,
   2,4,"eel",im+"/eel",0
 });
 dest_dir=({ 
      ir+"/river5", "north",
	ir+"/scoast2", "northwest",
	ir+"/river1", "southeast"
	   });
 }
 ::reset(arg);
}
