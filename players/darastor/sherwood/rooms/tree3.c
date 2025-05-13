inherit "/room/room";
#include "../listen.h"
#include "../tear.h"
#define TP this_player()

int is_search, is_whistle;

reset(arg){
   is_search=0;
   is_whistle=1;
 if (!arg){
 set_light(1);
 short_desc=("On the beech tree");
 long_desc="You are on the beech tree. Huge branches with green leaves are\n"+
           "around you.\n";

 smell="You smell wood odour.";

 dest_dir=({ "/players/goldsun/sherwood/room/shwood11","down" });

 items=({ "branch","You see a nest on it",
	  "leaf","A green beech leaf",
	  "nest","It is made of branches and leaves",
          "branches","There is a nest on the one",
          "leaves","They are waving in the wind"
        });

 }
 ::reset(arg);
}

init(){
 ::init();
add_action("search","search");
add_action("tear","tear");
add_action("listen","listen");
}

int search(string str){
object wh;
 notify_fail("Search what?\n");
 if (str=="nest"){
   if (!is_search){
     is_search=1;
     write("As you try to search the nest a bird flies out of it.\n");
     move_object(clone_object("players/goldsun/sherwood/monster/bird"),
		this_object());
     return 1;
   }
   if (is_whistle){
    is_whistle=0;
    write("You search the nest and find a whistle.\n");
    wh=clone_object("/players/goldsun/white_tower/obj/c_whistle");
    if (transfer(wh,TP)){
      write("You can't carry that much.\n");
      transfer(wh,this_object());
    }
    return 1;
   }
   write("Someone was faster than you.\n");
   return 1;
  }
}
