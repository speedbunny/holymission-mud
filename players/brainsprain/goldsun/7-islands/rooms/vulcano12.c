inherit "/players/brainsprain/goldsun/7-islands/rooms/genVulcano";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 dest_dir=({
  ir+"/vulcano8","north",
  ir+"/vulcano11","west",
  ir+"/vulcano16","south",
	   });
}
 ::reset(arg);  
}

