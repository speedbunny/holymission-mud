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
  set_name("Black Wolf");
  set_short(master->SNAME + "'s Black Wolf");
  set_long("A large Wolf with thick black fur and yellow-green eyes.\n");
  set_alias("wolf");
  set_level(1);
  set_ac(6);
  set_wc(7);
  set_hp(70 + random(20));
  set_ep(0);
  load_a_chat(50, ({
    "Black Wolf snarls and lashes out with its claws.\n",
    "Black Wolf's fangs gleam as it snaps is slavering jaws.\n"
  }));
  motion = "pads silently";
  bansp = 10;
  reqlevel = 1;
  msg = "Te arcesso ut facies muem iussum";
  ter = 0;
  return 1;
}
