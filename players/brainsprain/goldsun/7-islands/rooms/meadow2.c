inherit "/players/brainsprain/goldsun/7-islands/rooms/genMeadow";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,3,"bunny",im+"/bunny",0
 });
 dest_dir=({ 
  ir+"/meadow1", "north",
  ir+"/ecoast1",  "south"
           });
 }
 ::reset(arg);
}
