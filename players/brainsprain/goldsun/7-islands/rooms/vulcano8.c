inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
   1,6,"vmon",im+"/vulc_monster",0
 });
dest_dir=({    
      ir+"/vulcano4","north",
      ir+"/vulcano7", "west",
	ir+"/vulcano12","south" 
	   });
}
 ::reset(arg);  
}

