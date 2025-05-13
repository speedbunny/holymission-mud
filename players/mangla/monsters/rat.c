inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Rat");
    set_alias("rat");
    set_race("mammal");
    set_size(1);
    set_level(2);
    set_short("Rat");
    set_long("The rat flashes his sharp front teeth as he looks at you.\n");
    set_number_of_arms(2);
    set_n_wc(1);
/*
    set_wc(2);
*/
    set_ac(1);
    set_hp(30+random(10));
    set_al(0);
    set_dex(3);
    set_aggressive(0);
    add_money(5);
  }
}

