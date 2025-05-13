#include "../monkway.h"
inherit "obj/monster";

reset(arg) {
object ob;

  ::reset(arg);

  if(!arg) { 
    set_name("golem");
    set_alt_name("stone golem");
    set_short("A Stone Golem");
    set_long("You see a big strong looking Stome Golem.\n");
    set_race("golem");
    set_size(5);
    set_level(40);
    set_hp(2000);
    set_al(-10);
    set_aggressive(1);
    set_ac(12);
    set_whimpy();
    move_object(clone_object(OBJ+"club"),TO);
    command("wield club");
}
}


