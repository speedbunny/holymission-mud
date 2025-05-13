inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Sir Lancelot");
     set_alt_name("lancelot");
     set_alias("sir");
     set_race("human");
     set_gender(1);
     set_short("Lord of the Lance");
     set_long("He is an old man, wearing gleaming white armour\n\n");
     set_level(55);
     set_al(750);
     set_wc(50);
     set_ac(25);
     set_spell_mess2("Lancelot deals you a vicious blow !!\n");
     set_spell_mess1("Lancelot shows his combat experience.\n");
     set_spell_dam(30);
     set_chance(10);
     add_money(1300 + random(500));
     set_own_env("earth");
  }
}
