inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  
  dest_dir=({ 
      ir+"/ridge4", "northwest",
	ir+"/inland13","south",
	ir+"/ridge6", "southeast"
            });
	    

 }
 ::reset(arg);
}
