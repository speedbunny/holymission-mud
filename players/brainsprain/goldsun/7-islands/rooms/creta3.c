inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 if (arg) return;

 dest_dir=({
     ir+"/creta2","north",
     ir+"/creta6","east",
     ir+"/creta4","south",
	   });
  
}
