inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 dest_dir=({
      ir+"/rcoast4", "northeast",
      ir+"/vulcano3","west",
	ir+"/vulcano8","south" 
	   });
}
 ::reset(arg);  
}

