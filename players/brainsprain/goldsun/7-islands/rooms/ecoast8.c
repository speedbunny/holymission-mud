inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,5,"crab",im+"/crab",0
 });
 dest_dir=({ 
  ir+"/ecoast7",  "northeast",
  ir+"/meadow6", "east",
  ir+"/meadow1", "southeast",
  ir+"/ecoast9",  "south"
	   });
 }
 ::reset(arg);
}
