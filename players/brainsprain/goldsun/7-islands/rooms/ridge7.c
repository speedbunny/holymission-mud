inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  clone_list=({
      1,2,"frost",im+"/frost",0
  });  
  dest_dir=({ 
      ir+"/ridge6", "northeast",
	ir+"/ridge8", "southwest"
            });
	    

 }
 ::reset(arg);
}
