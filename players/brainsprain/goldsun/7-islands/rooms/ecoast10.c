inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 clone_list=({
       1,1,"crab",im+"/crab",0
      });
 dest_dir=({
    ir+"/ecoast9","north",
    ir+"/ecoast1","southeast",
	   });
 ::reset(arg);
}
