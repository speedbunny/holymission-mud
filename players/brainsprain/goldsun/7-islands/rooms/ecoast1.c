inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
if (arg) return;
 
 dest_dir=({
             ir+"/ecoast10","northwest",
             ir+"/meadow2","north",
             ir+"/ecoast","east",
	   });
  
}
