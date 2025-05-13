inherit "/players/brainsprain/goldsun/7-islands/rooms/genMeadow";  
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

int _is;

void reset(int arg){
 _is=0;
 if (!arg){
 clone_list=({
  1,2,"raccoon",im+"/raccoon",0
 });
  ::reset(arg); 
  long_desc=(
"You are in the middle of a meadow on a beautiful island.  High green "+
"grass is slowly waving in the wind and you want to lie here and watch "+
"the clouds above. The whole island is hilly and grassy.  You notice an "+
"odd bump on the ground.\n");
  items=({
  "bump","Maybe you could dig down...",
  });
 dest_dir=({ 
  ir+"/ecoast7", "north",
  ir+"/ecoast8", "west",
  ir+"/meadow1","south",
  ir+"/meadow5","east"
  });
 }
}

int dig(string str){
 notify_fail("Dig where?\n");
 if (str=="down"){
  if (!_is){
     write("You dig down.\nYou find a stone.\n");
     move_object(clone_object(ii+"/emerald"),
         this_player());
     _is=1;
   } else  write("You dig down a small hole.\n");
  say(this_player()->query_name()+" digs down.\n");
  return 1;
  }
}
