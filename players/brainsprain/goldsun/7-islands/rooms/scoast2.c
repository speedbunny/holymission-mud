inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 dest_dir=({ 
     ir+"/scoast3", "northeast",
     ir+"/river5", "east",
     ir+"/river6", "southeast",
     ir+"/scoast1", "south"
	   });
 }
 ::reset(arg);
}
