inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  clone_list=({
    1,1,"frost",im+"/frost",0});
  dest_dir=({ 
      ir+"/ridge4", "southeast",
	ir+"/inland5","south",
	ir+"/ridge2", "southwest"
            });
	    
 }
 ::reset(arg);
}
