inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){

 dest_dir=({    
  ir+"/ridge3", "north",
  ir+"/ridge4", "east",
  ir+"/inland6","south",
  ir+"/ridge2", "west"
  });
}
 ::reset(arg);
}

