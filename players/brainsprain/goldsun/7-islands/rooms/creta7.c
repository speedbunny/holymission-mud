inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({
    ir+"/creta6","north",
    ir+"/creta4","west",
    ir+"/creta10","east",
	   });
  
}
