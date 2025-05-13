inherit "/obj/monster";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    object crown;
    
    set_name("sea horse");
    set_alias("sea-horse");
    set_alt_name("seahorse");
    set_short("A sea horse");
    set_long("A small sea horse with a tiny golden crown.\n");
  set_level(1);
    set_al(50);
    set_hp(1);
    set_wc(5);
    set_ac(1);
    set_aggressive(0);
    set_no_steal();
    set_move_at_reset();
    set_wimpy(25);
    set_dead_ob(this_object());
    set_size(1);
    
    /* the crown */
    crown = clone_object("obj/armour");
    crown->set_id("crown");
    crown->set_short("A tiny crown");
    crown->set_long("A tiny crown made of gold.\n");
   crown->set_value(0);
    crown->set_size(1);
    crown->set__ac(1);
    crown->set_weight(1);
    transfer(crown,this_object());
    command("wear crown");
} }
monster_died(ob) {
  this_player()->add_exp(-10);
   return 0;
}

