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
  set_name("Water Element");
  set_short(master->SNAME + "'s Water Element");
  set_long("This creature is made entirely of water. The light refracts\n" +
	   "strangely through its body as it continually shifts its form.\n");
  set_alias("water");
  set_race("element");
  set_level(12);
  set_ac(13);
  set_wc(13);
  set_hp(300 + random(60));
  set_ep(0);
  set_chance(15);
  set_spell_mess1("Water Element hurls a tidal wave!");
  set_spell_mess2("Water Element hurls a tidal wave at you!");
  set_spell_dam(20);
  load_a_chat(50, ({
    "Water Element engulfs the area in drowning water.\n",
    "Water Element surges up into a huge mass and splashes down hard.\n"
  }));
  motion = "gathers into a tidal wave and moves";
  bansp = 30;
  reqlevel = 12;
  msg = "Te arcesso de aquae elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
