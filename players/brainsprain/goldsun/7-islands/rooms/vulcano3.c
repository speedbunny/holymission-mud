inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,3,"vmon",im+"/vulc_monster",0
 });

 dest_dir=({    
      ir+"/vulcano2", "west",
	ir+"/vulcano7", "south",
	ir+"/vulcano4","east" 
	   });
}
 ::reset(arg);  
}

