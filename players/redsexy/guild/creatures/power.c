inherit "players/redsexy/guild/creatures/attacker";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
}

setup() {
  set_name("Power Element");
  set_short(master->SNAME + "'s Power Element");
  set_long("This creature is difficult to focus on; it moves quickly\n" +
	   "and changes aspect at incredible speeds.\n");
  set_alias("power");
  set_race("element");
  set_level(23);
  set_ac(23);
  set_wc(24);
  set_hp(520 + random(60));
  set_ep(0);
  set_chance(15);
  set_spell_mess1("Power Element shoots out crackling electricity!");
  set_spell_mess2("Power Element electrifies you!");
  set_spell_dam(45);
  load_a_chat(50, ({
    "Power Element calls a bolt of lightning down from the sky.\n",
    "Power Element bursts out in a flash of energy.\n"
  }));
  motion = "flashes in a blink";
  bansp = 35;
  reqlevel = 23;
  msg = "Te arcesso de potestatis elemento ut facies meum iussum";
  ter = 0;
  return 1;
}
