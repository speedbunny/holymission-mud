inherit "/players/brainsprain/goldsun/7-islands/rooms/genRidge";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  dest_dir=({ 
   ir+"/ridge2", "northeast",
            });
	    

 }
 ::reset(arg);
}
