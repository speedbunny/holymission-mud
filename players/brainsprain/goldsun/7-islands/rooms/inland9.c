inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,1,"wolf",im+"/wolf",0,
  2,1,"bear",im+"/ice_bear",0});

 dest_dir=({    
  ir+"/inland8", "north",
  ir+"/ridge10","west",
  ir+"/ridge9", "south"
           });
 }
 ::reset(arg);
}
