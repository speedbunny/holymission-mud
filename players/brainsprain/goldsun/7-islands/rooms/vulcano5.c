inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 dest_dir=({     
      ir+"/vulcano1", "north",
      ir+"/vulcano6", "east",
	ir+"/vulcano9", "south" 
	   });
}
 ::reset(arg);  
}

