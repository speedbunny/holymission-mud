inherit "/players/brainsprain/goldsun/7-islands/rooms/genMeadow";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,1,"swarm",im+"/gnat",0
 });
 dest_dir=({ 
  ir+"/meadow5", "north",
  ir+"/ecoast5",  "northeast",
  ir+"/meadow3", "south",
  ir+"/meadow1", "west"
           });
 }
 ::reset(arg);
}

