inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 
 if (!arg)
 {
  clone_list=({
     1,1,"frost",im+"/frost",0
  });
  dest_dir=({ 
      ir+"/ridge5", "northwest",
	ir+"/inland13","west",
	ir+"/ridge7", "southwest"
            });
	    

 }
 ::reset(arg);
}
