inherit "/players/brainsprain/goldsun/7-islands/rooms/EgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,3,"crab",im+"/crab",0
 });
 
 dest_dir=({ 
   ir+"/ecoast3",  "northeast",
   ir+"/meadow3", "north",
   ir+"/ecoast1",  "west"
	   });
 }
 ::reset(arg);
}
