inherit "/players/brainsprain/goldsun/7-islands/rooms/tgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
  clone_list=({
    1,1,"crab",im+"/crab",0
  });

  dest_dir=({ 
      ir+"/tcoast6", "northeast",
      ir+"/tcoast4", "southwest"
	   });

 }
 ::reset(arg);
}

