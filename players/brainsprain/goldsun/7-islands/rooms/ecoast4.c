inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,3,"crab",im+"/crab",0});
 dest_dir=({ 
  ir+"/ecoast5", "north",
  ir+"/ecoast3", "south",  
	   });
 }  
 ::reset(arg);
}
