inherit "/players/brainsprain/goldsun/7-islands/rooms/sgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
    1,3,"seagull",im+"/seagull",0
 });

 dest_dir=({ 
     ir+"/scoast4", "northeast",
     ir+"/river4", "east",
     ir+"/river5", "south",
     ir+"/scoast10","southwest"
	   });
 }
 ::reset(arg);
}
