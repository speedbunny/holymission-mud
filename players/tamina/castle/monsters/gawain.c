inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Sir Gawain");
     set_alt_name("gawain");
     set_alias("sir");
     set_race("human");
     set_gender(1);
     set_short("Sir Gawain");
     set_long("Sir Gawain is very large, and very muscular\n");
     set_size(4);
     set_level(45);
     set_al(600);
     set_wc(56);
     set_ac(29);
     set_spell_mess2("Gawain smacks you in the head\n");
     set_spell_mess1("Gawain lets fly a punch.\n");
     set_spell_dam(20);
     set_chance(9);
     set_own_env("earth");
  }
}
