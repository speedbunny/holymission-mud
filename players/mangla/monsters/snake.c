inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Large Snake");
    set_alias("snake");
    set_race("reptile");
    set_size(4);
    set_level(14);
    set_short("Constrictor Snake");
    set_long("This is a fearsome looking snake that wraps itself\n" +
             "around its prey and squeezes the life from them before\n" +
             "devouring its favorite meal, humanoids.\n");
    set_wc(15);
    set_ac(3);
    set_hp(200+random(50));
    set_al(-100);
    set_dex(10);
    set_aggressive(0);
    add_money(0);
    set_chance(20);
    set_spell_dam(25);
    set_spell_mess2("The snake manages to get its coils around you for a moment and squeeze.");
    set_spell_mess1("The snake wraps up its opponent and squeezes.");
  }
}

