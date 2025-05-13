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
  set_name("Arch-Demon");
  set_short(master->SNAME + "'s Arch-Demon");
  set_long("This infernal creature resides in the lowest depths of the\n" +
	   "Underworld. You sense a great power surrounding it and would\n" +
	   "be wise to think twice before attacking.\n");
  set_alias("arch");
  set_race("demon");
  set_level(29);
  set_ac(29);
  set_wc(30);
  set_hp(900 + random(200));
  set_ep(0);
  set_chance(20);
  set_spell_mess1("Arch-Demon lashes out its tail!");
  set_spell_mess2("Arch-Demon slashes you with its tail!");
  set_spell_dam(60);
  load_a_chat(50, ({
    "Arch-Demon rips and tears with its blackened claws.\n",
    "Arch-Demon's fangs drip blood as it bites down hard.\n"
  }));
  motion = "treads gravely";
  bansp = 50;
  reqlevel = 29;
  msg = "Te liberato inferis ut facies meum iussum";
  ter = 1;
  return 1;
}

hit_player(arg, type) {
  int i;
  object inv;
  if(random(FIRE_CHN)) {
    TELLR(ENV(TO), "Arch-Demon engulfs the area in Hellfire!\n");
    inv = all_inventory(ENV(TO));
    for(i = 0; i < sizeof(inv); i++)
      if((inv[i]->query_attack() == TO) ||
	 (TO->query_attack() == inv[i])) {
	TELL(inv[i], "You are scorched by infernal flames!\n");
	TELLS(inv[i]->NAME + " is scorched by infernal flames!\n", inv[i]);
	inv[i]->HIT(FIRE_DAM);
      }
  }
  return ::hit_player(arg, type);
}
