inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Wild Boar");
    set_alias("boar");
    set_race("mammal");
    set_size(2);
    set_level(15);
    set_short("Wild Boar");
    set_long("This is a rather large and mean looking boar that sees you\n" +
             "you as a tasty treat. Perhaps you should...RUN!!\n");
    set_wc(10);
    set_ac(7);
    set_hp(70+random(20));
    set_al(-80);
    set_int(6);
    set_str(6);
    set_con(6);
    set_wis(6);
    set_chr(6);
    set_dex(10);
    set_aggressive(1);
    add_money(10);
  }
}

