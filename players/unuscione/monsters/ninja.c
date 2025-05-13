inherit "obj/monster";

#include "/players/unuscione/def.h"

reset(arg){
 ::reset();
 if(arg) return;
set_short("Ninja Guard");
set_long("A ninja guard stands watch over the san room.\n");
set_name("ninja");
set_alias("guard");
set_level(50);
set_wc(80);
set_hp(50000);
return;
}
init(){
 ::init();
if(TP->query_level()<25){
  write("The Ninja Guard moves to attack the Intruder.\n");
   this_player()->attacked_by(this_object());
  return;
   }
 add_action("_accept","accept");
}

_accept(){
  if(TP->query_level()<25){
   return 0;
   }
   else {
   write("You are not a true san, leave!\n");
   TP->attacked_by(TO);
   return 1;
  }
}
