#include "../monkway.h"
inherit "obj/monster";

reset(arg) {
object ob;

  ::reset(arg);

  if(!arg) { 
    set_name("golem");
    set_alt_name("stone golem");
    set_short("A Stone Golem");
    set_long("You see a very weak looking Stome Golem.\n");
    set_race("golem");
    set_size(5);
    set_level(30);
    set_hp(1600);
    set_al(-10);
    set_aggressive(1);
    set_ac(8);
    move_object(clone_object(OBJ+"club"),TO);
    command("wield club");
}
}

