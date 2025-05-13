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
  set_name("Lesser Demon");
  set_short(master->SNAME + "'s Lesser Demon");
  set_long("A misshapen creature from the lower Planes, this hideous\n" +
	   "Demon almost makes you retch when you look at it.\n");
  set_alias("lesser");
  set_race("demon");
  set_level(26);
  set_ac(26);
  set_wc(27);
  set_hp(600 + random(100));
  set_ep(0);
  set_chance(20);
  set_spell_mess1("Lesser Demon lashes out its tail!");
  set_spell_mess2("Lesser Demon whips you with its tail!");
  set_spell_dam(50);
  load_a_chat(50, ({
    "Lesser Demon rips and tears with its blackened claws.\n",
    "Lesser Demon's fangs drip blood as it bites down hard.\n"
  }));
  motion = "slithers";
  bansp = 40;
  reqlevel = 26;
  msg = "Te liberato inferis ut facies meum iussum";
  ter = 0;
  return 1;
}
