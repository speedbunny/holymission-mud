inherit "/players/brainsprain/goldsun/7-islands/rooms/genMeadow";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,7,"ant",im+"/ant",0
 });
 dest_dir=({ 
  ir+"/meadow6", "north",
  ir+"/ecoast8",  "northwest",
  ir+"/meadow2", "south",
  ir+"/meadow4", "east"
  });
 }
 ::reset(arg);
}
