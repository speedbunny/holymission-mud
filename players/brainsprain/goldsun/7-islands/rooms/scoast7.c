inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 dest_dir=({ 
     ir+"/scoast6", "north",
     ir+"/scoast8", "southwest"
	   });
 }
 ::reset(arg);
}
