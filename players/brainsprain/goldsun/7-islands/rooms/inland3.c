inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){

 dest_dir=({    
  ir+"/inland2","north", 
  ir+"/inland7","east",
  ir+"/inland1","west"
  });
}
 ::reset(arg);
}
