inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,1,"duckling",im+"/duckling",0
 });
 dest_dir=({ 
  ir+"/ecoast6",  "east",
  ir+"/meadow6", "south",
  ir+"/ecoast8",  "southwest"
	   });
 }
 ::reset(arg);
}
