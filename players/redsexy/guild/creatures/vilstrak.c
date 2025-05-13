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
  set_name("Vilstrak");
  set_short(master->SNAME + "'s Vilstrak");
  set_long("A large, rock-skinned beast in roughly the shape of a human.\n");
  set_alias("vilstrak");
  set_level(9);
  set_ac(9);
  set_wc(10);
  set_hp(180 + random(40));
  set_ep(0);
  load_a_chat(50, ({
    "Vilstrak roars and strikes out.\n",
    "Vilstrak slams down its rocky fists.\n"
  }));
  motion = "stomps heavily";
  bansp = 20;
  reqlevel = 9;
  msg = "Te arcesso de terrae elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
