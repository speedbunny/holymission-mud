inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Sir Bedevere");
     set_alt_name("bedevere");
     set_alias("sir");
     set_race("human");
     set_gender(1);
     set_short("Bedevere the Wise");
     set_long("This tall man has a very wise look on his face.\n");
     set_level(40);
     set_al(500);
     set_wc(35);
     set_ac(20);
     set_spell_mess2("Bedevere slaps you viciously !!\n");
     set_spell_mess1("Bedevere waves his hands about !!\n");
     set_spell_dam(10);
     set_chance(8);
     set_own_env("earth");

  }
}
