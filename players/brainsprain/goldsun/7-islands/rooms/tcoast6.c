inherit "/players/brainsprain/goldsun/7-islands/rooms/tgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
  dest_dir=({  
      ir+"/tcoast7", "northeast",
      ir+"/tcoast5", "southwest"
	   });

 }
 ::reset(arg);
}

