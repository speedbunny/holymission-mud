inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 dest_dir=({ 
     ir+"/scoast5", "northwest",
     ir+"/river3", "west",
     ir+"/river2", "southwest",
     ir+"/scoast7", "south"
	   });
 }
 ::reset(arg);
}
