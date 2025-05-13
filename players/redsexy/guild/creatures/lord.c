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
  set_name("Demon Lord");
  set_short(master->SNAME + "'s Demon Lord");
  set_long("The terrifying thing about this beast is its grotesque parody\n" +
	   "of the human form. Its twisted, gnarled shape is covered with\n" +
	   "horns, scales, and fur; its yellow eyes burn with hatred for\n" +
	   "all things human.\n");
  set_alias("lord");
  set_race("demon");
  set_level(28);
  set_ac(28);
  set_wc(29);
  set_hp(800 + random(100));
  set_ep(0);
  set_chance(20);
  set_spell_mess1("Demon Lord lashes out its tail!");
  set_spell_mess2("Demon Lord slashes you with its tail!");
  set_spell_dam(50);
  load_a_chat(50, ({
    "Demon Lord rips and tears with its blackened claws.\n",
    "Demon Lord's fangs drip blood as it bites down hard.\n"
  }));
  motion = "strides";
  bansp = 40;
  reqlevel = 28;
  msg = "Te liberato inferis ut facies meum iussum";
  ter = 1;
  return 1;
}

hit_player(arg) {
  int i;
  object inv;
  if(random(TENT_CHN)) {
    TELLR(ENV(TO), "Demon Lord whirls and whips its tentacled arms!\n");
    inv = all_inventory(ENV(TO));
    for(i = 0; i < sizeof(inv); i++)
      if((inv[i]->query_attack() == TO) ||
	 (TO->query_attack() == inv[i])) {
	TELL(inv[i], "A tentacle strikes you hard!\n");
	TELLS("A tentacle strikes " + inv[i]->NAME + "!\n", inv[i]);
	inv[i]->HIT(TENT_DAM);
      }
  }
  return ::hit_player(arg);
}
