inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 dest_dir=({ 
  ir+"/rcoast3","west",
  ir+"/vulcano4","southwest",
  ir+"/rcoast5", "south"
	   });
  
 }
 ::reset(arg);
}
