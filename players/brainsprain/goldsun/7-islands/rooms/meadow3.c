inherit "/players/brainsprain/goldsun/7-islands/rooms/genMeadow";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

reset(arg){
 if (!arg){
 clone_list=({
  1,2,"mouse",im+"/mouse",0
 });
 dest_dir=({ 
  ir+"/meadow4", "north",
  ir+"/ecoast2", "south",
 });
 }
 ::reset(arg);
}
