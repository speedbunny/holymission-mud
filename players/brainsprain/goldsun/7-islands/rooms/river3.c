inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,1,"eagle",im+"/eagle",0,
    2,4,"eel",im+"/eel",0
 });
 dest_dir=({ 
      ir+"/scoast5", "north",
      ir+"/scoast6", "east",
	ir+"/river2", "south",
	ir+"/river8", "west"
	   });
 }
 ::reset(arg);
}
