inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,2,"vmon",im+"/vulc_monster",0});
 dest_dir=({    
      ir+"/rcoast1", "northeast",
      ir+"/vulcano2","east",
	ir+"/vulcano5","south" 
	   });
}
 ::reset(arg);  
}

