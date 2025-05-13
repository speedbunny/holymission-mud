inherit "/obj/monster";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gnats");
  set_short("A huge swarm of gnats");
  set_long("A huge swarm of gnats.\n");
  set_alias("swarm");
  set_race("insect");
  set_level(2);
  set_ac(100);
  set_wc(5);
  set_aggressive(1);
  set_dead_ob(TO);
  load_a_chat(50, ({
    "The gnats swarm around you.\n",
    "BZZZZ ZZ ZZZZZ\n",
    "A gnat buzzes in your ear!\n",
    "You are stung by a gnat!\n",
    "You swat at the swarm of gnats.",
    "You smack and kill a gnat that has landed on you.\n"
  }));
  load_chat(50, ({
    "BZZZ ZZZZZZZZ ZZZ ZZZ\n",
    "The gnats buzz annoyingly.\n"
  }));
}

monster_died() {
  destruct(TO);
  return 1;
}
