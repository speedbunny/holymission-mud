inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 dest_dir=({ 
     ir+"/scoast3", "southwest",
     ir+"/river4", "south",
     ir+"/scoast5", "southeast"
	   });
 }
 ::reset(arg);
}
