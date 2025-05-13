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
  set_name("Wind Element");
  set_short(master->SNAME + "'s Wind Element");
  set_long("You can feel the presence of this creature more than see it;\n" +
	   "It has little more material form than wisps of fast-moving\n" +
	   "wind, but you sense that it is powerful indeed.\n");
  set_alias("wind");
  set_race("element");
  set_level(13);
  set_ac(13);
  set_wc(14);
  set_hp(360 + random(60));
  set_ep(0);
  set_chance(15);
  set_spell_mess1("Wind Element blasts forth a huge gust of air!");
  set_spell_mess2("Wind Element blasts you with a huge gust of air!");
  set_spell_dam(25);
  load_a_chat(50, ({
    "Wind Element whirls about violently.\n",
    "Wind Element shreiks and howls as it buffets the area with wind.\n"
  }));
  motion = "blows itself";
  bansp = 30;
  reqlevel = 13;
  msg = "Te arcesso de venti elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
