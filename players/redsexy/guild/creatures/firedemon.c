inherit "obj/monster";

#include "/players/redsexy/defs.h"

object sword;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("fire demon");
  set_alias("demon");
  set_short("An evil Fire Demon");
  set_long("A hideous creature from the lowest Plane of Elemental Fire,\n" +
	   "the demon stares at you with unabashed hatred.\n");
  set_race("demon");
  set_level(25);
  set_ep(0);
  set_wc(1);
  set_al(-1000);
  set_prevent_poison(1);
  set_dead_ob(TO);
  load_a_chat(20, ({
    "The fire demon spews raw flames from its mouth!\n",
    "Fire demon massacred you to small fragments.\n",
  }));
}

hit_player(arg) {
  object att, sword;
  att = TO->query_attack();
  if(att && present(att, ENV(TO))) {
    sword = present("flamesword", att);
    if(sword && att->query_wielded() == sword) {
      TELLR(ENV(TO), "With its own mind, the flamesword slashes " +
	    "mercilessly at the demon!\n");
      ::hit_player(5000);
    }
    else TELLR(att, "The demon easily deflects your attack.\n");
    return 1;
  }
  return 1;
}

monster_died() {
  TELLR(ENV(TO), "The fire demon screams with a shrill shriek as its body\n" +
	"evaporates and returns to its own dimension.\n");
  ENV(TO)->set_killed(1);
  destruct(TO);
  return 1;
}
