inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({ 
        ir+"/creta3","north",
        ir+"/creta7","east",
	   });
  
}
