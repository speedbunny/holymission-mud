inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,3,"vmona",im+"/vulc_monster_a",0,
  2,2,"vmon",im+"/vulc_monster",0
 });
 dest_dir=({    
      ir+"/vulcano2", "north",
      ir+"/vulcano5", "west",
	ir+"/vulcano10","south", 
	ir+"/vulcano7", "east"
	   });
}
 ::reset(arg);  
}

