inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  
  dest_dir=({ 
   ir+"/ridge11","northwest",
   ir+"/inland9","west",
   ir+"/ridge9", "southeast",
            });
	    

 }
 ::reset(arg);
}
