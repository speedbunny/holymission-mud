inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  dest_dir=({ 
      ir+"/ridge3", "northwest",
	ir+"/inland5","west",
	ir+"/ridge5", "southeast"
            });
	    

 }
 ::reset(arg);
}
