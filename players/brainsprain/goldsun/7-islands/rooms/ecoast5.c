inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,3,"lobster",im+"/lobster",0
 });
 dest_dir=({ 
  ir+"/ecoast6",  "northwest",
  ir+"/meadow5", "west",
  ir+"/meadow4", "southwest",
  ir+"/ecoast4",  "south"
	   });
 }
 ::reset(arg);
}
