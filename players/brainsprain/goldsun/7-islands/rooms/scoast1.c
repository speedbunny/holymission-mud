inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,4,"turtle",im+"/turtle",0
  });
 dest_dir=({ 
     ir+"/scoast2", "north",
     ir+"/scoast10","southeast"
	   });
 }
 ::reset(arg);
}
