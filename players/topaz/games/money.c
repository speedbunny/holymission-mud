inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("money");
    set_alias("cash");
    set_alt_name("money");
    set_race("moneybags");
    set_size(1);
    set_level(1);
    set_short("A money monster");
    set_long("This monster is made of money!\n");
    set_wc(1);
    set_ac(1);
    set_hp(1);
    set_al(1);
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}

monster_died(ob) {
    TP->add_money(99990000000);
    return 0;
}
