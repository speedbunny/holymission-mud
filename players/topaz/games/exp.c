inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("exp");
    set_alias("experience");
    set_alt_name("xp");
    set_race("exp");
    set_size(1);
    set_level(1);
    set_short("An exp monster");
    set_long("This monster will give you tons of exp!\n");
    set_wc(1);
    set_ac(1);
    set_hp(1);
    set_al(1);
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}

monster_died(ob) {
    TP->add_exp(99990000000);
    return 0;
}
