inherit "obj/monster";
#include "/players/redsexy/defs.h"
reset(arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("Salacious Crumb");
  set_alt_name("salacious");
  set_alias("crumb");
  set_level(29);
  set_hp(3000);
  set_wc(39);
  set_ac(20);
  set_gender(1);
  set_al(-500);
  set_short("Salacious Crumb");
  set_long("Salacious Crumb is a short, wiry creature.  He is Jabba's residential comedian.\n");
  set_ac(11);
  set_spell_mess1("You giggle inanely.\n");
  set_spell_mess2("Salacious Crumb's joke makes you laugh so hard you hurt yourself!\n");
  set_spell_dam(50);
  set_chance(15);
}

