inherit "/players/brainsprain/goldsun/7-islands/rooms/tgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 if (!arg){
  long_desc=
   "You are standing on the coast of Topaz island. To the north you can\n"+
   "see tall cliff with a small pass in it. The ground consists of\n"+
   "sand. Small waves are rolling towards the island.\n";
 
  items+=({"pass","A pass. It is possible to climb it"
          });
  dest_dir=({ PATH+"coast6", "southwest"
	   });

 }
}

init(){
 ::init();
add_action("go_up","climb");
}

int go_up(string str){
 notify_fail("Climb what?\n");
 if (str=="up pass" || str=="pass" || str=="cliff" || str=="up cliff"
      || str=="up"){
   write("Uf.\nUf.\nUf.\nYou climb up the cliff.\n");
   this_player()->move_player("up#"+ir+"desert16");
   return 1;
 }
}
