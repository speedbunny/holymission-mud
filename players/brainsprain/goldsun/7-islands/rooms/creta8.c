inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({
   ir+"/creta5","west",
   ir+"/creta9","south",
   ir+"/creta11","east",
	   });
}
