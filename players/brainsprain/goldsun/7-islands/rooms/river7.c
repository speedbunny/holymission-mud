inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,2,"trout",im+"/trout",0,
    2,1,"eel",im+"/eel",0
 });
 dest_dir=({ 
      ir+"/river8", "north",
	ir+"/river1", "south"
	   });
 }
 ::reset(arg);
}
