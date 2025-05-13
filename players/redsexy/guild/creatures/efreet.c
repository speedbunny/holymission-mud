inherit "players/redsexy/guild/creatures/attacker";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"


object sword;

reset(arg) {
  ::reset(arg);
  if(!sword) {
    sword = clone_object("players/redsexy/guild/objects/firesword");
    MOVE(sword, TO);
  }
  if(arg) return;
}

setup() {
  set_name("Efreet");
  set_short(master->SNAME + "'s Efreet");
  set_long("A tall humanoid creature engulfed in searing flame.\n");
  set_alias("efreet");
  set_level(10);
  set_ac(10);
  set_wc(11);
  set_hp(220 + random(40));
  set_ep(0);
  load_a_chat(50, ({
    "Efreet strikes with burning hands.\n",
    "Efreet slashes its sword, leaving a trail of flame.\n"
  }));
  motion = "leaves flaming tracks as it walks";
  bansp = 20;
  reqlevel = 10;
  msg = "Te arcesso de ignis elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
