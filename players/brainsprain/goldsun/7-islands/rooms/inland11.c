inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,1,"frost",im+"/wolf",0
 });

 dest_dir=({
  ir+"/inland10","north",
  ir+"/inland13","east",
  ir+"/inland12","south",
  ir+"/inland7", "west"
  });
 }
 ::reset(arg);
}
