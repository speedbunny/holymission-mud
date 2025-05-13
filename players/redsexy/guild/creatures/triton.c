inherit "players/redsexy/guild/creatures/attacker";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

object trident;

reset(arg) {
  ::reset(arg);
  if(!trident) {
    trident = clone_object("players/redsexy/guild/objects/trident");
    MOVE(trident, TO);
  }
  if(arg) return;
}

setup() {
  set_name("Triton");
  set_short(master->SNAME + "'s Triton");
  set_long("A green-skinned humanoid creature with webbed feet and a\n" +
	   "long spiked tail.\n");
  set_alias("triton");
  set_level(7);
  set_ac(7);
  set_wc(8);
  set_hp(100 + random(40));
  set_ep(0);
  load_a_chat(50, ({
    "Triton swipes with its webbed claws.\n",
    "Triton lashes out its tail.\n",
    "Triton lunges forward its trident.\n"
  }));
  motion = "sloshes";
  bansp = 20;
  reqlevel = 7;
  msg = "Te arcesso de aquae elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
