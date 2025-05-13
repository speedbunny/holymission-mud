inherit "/players/goldsun/7-islands/topaz/room/genCoast";
#define PATH "players/goldsun/7-islands/topaz/room/"

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
   this_player()->move_player("up#"+PATH+"desert16");
   return 1;
 }
}
