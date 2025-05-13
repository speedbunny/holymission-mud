inherit "obj/monster";
#include "/players/redsexy/defs.h"
reset(arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("gamorrean guard");
  set_alt_name("gamorrean");
  set_alias("guard");
  set_level(20);
  set_hp(1500);
  set_wc(30);
  set_ac(11);
  set_al(-500);
  set_short("Gamorrean Guard");
  set_long("This is one of Jabba's guards, protecting his palace.\n");
  set_ac(11);
  set_spell_mess2("The guard spits in your face!\n");
  set_spell_mess1("The guard howls with pleasure as his claws pierce your skin.\n");
  set_spell_dam(24);
  set_chance(15);
}

init()
{
  ::init();
  add_action("_south","south");
}

_south()
{
  write("The guard laughs at your attempts to pass him!\n");
  TP->hit_player(10);
  TO->attack_object(TP);
  return 1;
}


