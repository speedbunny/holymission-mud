inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 dest_dir=({    
        ir+"/vulcano9", "north",
        ir+"/vulcano14","east"
	   });
}
 ::reset(arg);  
}

