inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,3,"wolf",im+"/wolf",0,
  2,1,"sighard",im+"/wizard",0,
  3,1,"frost",im+"/frost",0,
  4,1,"cermor",im+"/cermor",0
 });

 dest_dir=({    
  ir+"/inland6", "north",
  ir+"/inland11","east",
  ir+"/inland8", "south",
  ir+"/inland3", "west"
  });
 }
 ::reset(arg);
}

