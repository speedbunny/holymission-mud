inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 
 dest_dir=({
     ir+"/creta1","northwest",
     ir+"/creta2","west",
     ir+"/creta6","south",
     ir+"/creta9","southeast",
     ir+"/creta8","east",
	   });
  
}
