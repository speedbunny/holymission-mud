inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  
  dest_dir=({ 
      ir+"/ridge3", "northeast",
      ir+"/inland5", "east",
	ir+"/ridge1", "southwest"
            });
	    

 }
 ::reset(arg);
}
