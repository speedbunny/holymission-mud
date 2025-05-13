#include "../monkway.h"
inherit "obj/monster";

reset(arg) {
object ob;

  ::reset(arg);

  if(!arg) { 
    set_name("golem");
    set_short("A Stone Golem");
    set_long("You see a big strong looking Stome Golem.\n");
    set_race("golem");
    set_size(5);
    set_level(60);
    set_hp(3000);
    set_al(-10);
    set_ac(15);
    move_object(clone_object(OBJ+"stone_ring"),TO);
    command("wear ring");
}
}

 init() {
   call_out("check",4);
  ::init();
  }
  run_away() {
   return;
  }

 check() {
  if (!present("stone golem",environment())) {
    tell_room(environment(),short()+" shouts: Grrrr those wimps ran away.\n");
    call_out("check",14);
   }
  return 1;
 }
