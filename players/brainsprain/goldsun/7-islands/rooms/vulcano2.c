inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
    1,3,"vmon",im+"/vulc_monster",0
 });
 dest_dir=({    
      ir+"/vulcano1", "west",
	ir+"/vulcano6", "south",
	ir+"/vulcano3","east" 
	   });
}
 ::reset(arg);  
}

