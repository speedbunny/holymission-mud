inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,3,"wolf",im+"/wolf",0,
  2,1,"man",im+"/snow_man",0
 });

 dest_dir=({    
  ir+"/inland7", "north",
  ir+"/inland4", "west",
  ir+"/inland9", "south"
           });
 }
 ::reset(arg);
}
