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
  set_name("Greater Demon");
  set_short(master->SNAME + "'s Greater Demon");
  set_long("A hideous creature from the nether Planes with sharp fangs,\n" +
	   "jagged claws, tentacled arms, and a long spiked tail.\n");
  set_alias("greater");
  set_race("demon");
  set_level(27);
  set_ac(27);
  set_wc(28);
  set_hp(700 + random(100));
  set_ep(0);
  set_chance(20);
  set_spell_mess1("Greater Demon lashes out its tail!");
  set_spell_mess2("Greater Demon slashes you with its tail!");
  set_spell_dam(50);
  load_a_chat(50, ({
    "Greater Demon rips and tears with its blackened claws.\n",
    "Greater Demon's fangs drip blood as it bites down hard.\n"
  }));
  motion = "walks";
  bansp = 40;
  reqlevel = 27;
  msg = "Te liberato inferis ut facies meum iussum";
  ter = 0;
  return 1;
}

hit_player(arg, type) {
  int i;
  object inv;
  if(random(TENT_CHN)) {
    TELLR(ENV(TO), "Greater Demon whirls and whips its tentacled arms!\n");
    inv = all_inventory(ENV(TO));
    for(i = 0; i < sizeof(inv); i++)
      if((inv[i]->query_attack() == TO) ||
	 (TO->query_attack() == inv[i])) {
	TELL(inv[i], "A tentacle strikes you hard!\n");
	TELLS("A tentacle strikes " + inv[i]->NAME + "!\n", inv[i]);
	inv[i]->HIT(TENT_DAM);
      }
  }
  return ::hit_player(arg, type);
}
