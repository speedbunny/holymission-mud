inherit "/players/brainsprain/goldsun/7-islands/rooms/genRiver";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,1,"vuri",im+"/f_vuri",0,
    2,3,"eel",im+"/eel",0,
    3,1,"beaver",im+"/beaver",0
 });
 dest_dir=({ 
     ir+"/river4", "north",
     ir+"/river3", "east",
     ir+"/river7", "south",
     ir+"/river5", "west"
	   });
 }
 ::reset(arg);
}
