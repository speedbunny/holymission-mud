inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,4,"vmona",im+"/vulc_monster_a",0,
  2,1,"vmon",im+"/vulc_monster",0
 });
 dest_dir=({    
      ir+"/vulcano7", "north",
      ir+"/vulcano12","east",
	ir+"/vulcano15","south",
	ir+"/vulcano10","west"
	   });
}
 ::reset(arg);  
}

