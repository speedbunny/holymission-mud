inherit "obj/monster";

#include "/players/mangla/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Wolf");
    set_alias("wolf");
    set_race("mammal");
    set_size(2);
    set_level(5);
    set_short("Timber Wolf");
    set_long("This timber wolf seems to be content to ignore your\n" +
             "intrusion into its presence, but for how long?\n");
    set_wc(2);
    set_ac(2);
    set_hp(90+random(20));
    set_al(0);
    set_dex(5);
    set_aggressive(0);
    add_money(105);
  }
}

