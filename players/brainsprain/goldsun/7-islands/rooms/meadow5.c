inherit "/players/brainsprain/goldsun/7-islands/rooms/genMeadow";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

reset(arg){
 if (!arg){
 clone_list=({
  1,1,"toad",im+"/toad",0
 });
 dest_dir=({ 
  ir+"/ecoast6", "north",
  ir+"/meadow6","west",
  ir+"/meadow4","south",
  ir+"/ecoast5", "east"
 });
 }
 ::reset(arg);
}
