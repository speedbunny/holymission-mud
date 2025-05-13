inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Small Snake");
    set_alias("snake");
    set_race("reptile");
    set_size(1);
    set_level(1);
    set_short("Garter Snake");
    set_long("A harmless looking little snake that feeds on mice and\n" +
             "other small animals commonly found in gardens and woods.\n");
    set_wc(1);
    set_ac(1);
    set_hp(20+random(10));
    set_al(0);
    set_dex(2);
    set_aggressive(0);
    add_money(5);
  }
}

