inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,1,"vmona",im+"/vulc_monster_a",0,
  2,2,"vmon",im+"/vulc_monster",0
 });
 dest_dir=({    
      ir+"/vulcano5", "north",
      ir+"/vulcano10","east",
	ir+"/vulcano13","south" 
	   });
}
 ::reset(arg);  
}

