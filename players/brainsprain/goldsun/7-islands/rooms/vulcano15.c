inherit "/players/brainsprain/goldsun/7-islands/rooms/genVolcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,1,"vmona",im+"/vulc_monster_a",0,
  2,1,"vmon",im+"/vulc_monster",0
 });

 dest_dir=({    
      ir+"/vulcano11", "north",
     ir+"/vulcano14","west",
      ir+"/vulcano16","east",
	   });
}
 ::reset(arg);  
}

