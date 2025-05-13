#include "../monkway.h"
inherit "obj/monster";

reset(arg) {
object ob;

  ::reset(arg);

  if(!arg) { 
    set_name("golem");
    set_alt_name("stone golem");
    set_short("A Stone Golem");
    set_long("You see a big strong looking Stome Golem,\n"+
             "looking fearfully at you.\n");
    set_race("golem");
    set_size(5);
    set_level(15);
    set_hp(550);
    set_al(-10);
    set_ac(8);
    move_object(clone_object(OBJ+"hammer"),TO);
    command("wield hammer");
}
}

attack() {
  if (::attack()) {
     tell_room(environment(),"The golem shouts: I hate those fights !!!!\n");
     TO->run_away();
  }
 return 1;
}
