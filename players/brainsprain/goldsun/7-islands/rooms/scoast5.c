inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,4,"seagull",im+"/seagull",0});
 dest_dir=({ 
     ir+"/scoast4", "northwest",
     ir+"/river4", "west",
     ir+"/river3", "south",
     ir+"/scoast6", "southeast"
	   });
 }
 ::reset(arg);
}
