inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,1,"lobster",im+"/lobster",0
 });
 dest_dir=({ 
  ir+"/ecoast8",  "north",
  ir+"/ecoast10", "south"
	   });
 }
 ::reset(arg);
}
