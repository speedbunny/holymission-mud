inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,1,"wolf",im+"/wolf",0,
  2,1,"yeti",im+"/yeti",0
});

 dest_dir=({    
  ir+"/ridge5",  "north",
  ir+"/ridge6",  "east",
  ir+"/inland11","west"
           });
 }
 ::reset(arg);
}
