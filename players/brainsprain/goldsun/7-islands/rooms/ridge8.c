inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  dest_dir=({ 
      ir+"/ridge7", "northeast",
	ir+"/inland12","north",
	ir+"/ridge9", "southwest"
            });
	    

 }
 ::reset(arg);
}
