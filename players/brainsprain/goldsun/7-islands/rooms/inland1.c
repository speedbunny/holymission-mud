inherit "/players/brainsprain/goldsun/7-islands/rooms/genInland";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
  1,1,"man",im+"/snow_man",0
  });

 dest_dir=({
   ir+"/pass",   "west",
   ir+"/inland3","east",
   ir+"/ridge11","south"
   });
}
 ::reset(arg);
}
