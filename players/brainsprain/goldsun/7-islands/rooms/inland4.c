inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){

 clone_list=({
  1,1,"man",im+"/snow_man",0,
  2,1,"yeti",im+"/yeti",0,
  3,1,"wolf",im+"/wolf",0
 });

 dest_dir=({    
  ir+"/inland8","east"
 });
 }
 ::reset(arg);
}
