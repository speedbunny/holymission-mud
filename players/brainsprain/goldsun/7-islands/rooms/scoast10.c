inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,4,"crab",im+"/crab",0
 });
 dest_dir=({ 
    ir+"/scoast1", "northwest",
    ir+"/scoast9", "southeast"
	   });
 }
 ::reset(arg);
}
