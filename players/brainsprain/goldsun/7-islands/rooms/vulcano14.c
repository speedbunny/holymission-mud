inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
   1,1,"vmona",im+"/vulc_monster_a",0,
   2,6,"vmon",im+"/vulc_monster",0});

 dest_dir=({    
	ir+"/vulcano10","north",
      ir+"/vulcano15","east",
	ir+"/vulcano13","west" 
	   });
}
 ::reset(arg);  
}

