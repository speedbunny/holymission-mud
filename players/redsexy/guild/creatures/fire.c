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
  set_name("Fire Element");
  set_short(master->SNAME + "'s Fire Element");
  set_long("A large mass of pure flame that constantly flickers and\n" +
	   "changes shape.\n");
  set_alias("fire");
  set_race("element");
  set_level(15);
  set_ac(15);
  set_wc(16);
  set_hp(480 + random(520));
  set_ep(0);
  set_chance(15);
  set_spell_mess1("Fire Element hurls a ball of flame!");
  set_spell_mess2("Fire Element hurls a ball of flame at you!");
  set_spell_dam(35);
  load_a_chat(50, ({
    "Fire Element engulfs the area in flame.\n",
    "Fire Element contracts and fills the area with smoke.\n"
  }));
  motion = "burns a trail as it glides";
  bansp = 30;
  reqlevel = 15;
  msg = "Te arcesso de ignis elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
