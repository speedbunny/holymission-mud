inherit "/players/brainsprain/goldsun/7-islands/rooms/tgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
  dest_dir=({ 
      ir+"/tcoast3", "east",
      ir+"/tcoast1", "west"
	   });

 }
 ::reset(arg);
}

