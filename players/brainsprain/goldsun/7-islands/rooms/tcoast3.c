inherit "/players/brainsprain/goldsun/7-islands/rooms/tgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
  clone_list=({
    1,3,"turtle",im+"/turtle",0,
    2,5,"crab",im+"/crab",0});
  dest_dir=({ 
      ir+"/tcoast4", "east",
      ir+"/tcoast2", "west"
	   });

 }
 ::reset(arg);
}

