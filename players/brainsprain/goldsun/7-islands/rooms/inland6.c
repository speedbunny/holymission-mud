inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,3,"wolf",im+"/wolf",0,
  2,1,im+"bear",im+"/ice_bear",0,
  3,1,"fox",im+"/fox",0
 });

 dest_dir=({    
   ir+"/inland5", "north",
   ir+"/inland10","east",
   ir+"/inland7", "south",
   ir+"/inland2", "west"
   });
 }
 ::reset(arg);
}
