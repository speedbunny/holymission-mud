inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){

 dest_dir=({    
  ir+"/inland6", "west",
  ir+"/inland11", "south"
           });
 }
 ::reset(arg);
}
