inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 dest_dir=({ 
  ir+"/ecoast7",  "west",
  ir+"/meadow5", "south",
  ir+"/ecoast5",  "southeast"
	   });
 }
 ::reset(arg);
}
