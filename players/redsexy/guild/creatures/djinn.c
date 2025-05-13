inherit "players/redsexy/guild/creatures/attacker";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

object sword;

reset(arg) {
  ::reset(arg);
  if(!sword) {
    sword = clone_object("players/redsexy/guild/objects/windsword");
    MOVE(sword, TO);
  }
  if(arg) return;
}

setup() {
  set_name("Djinn");
  set_short(master->SNAME + "'s Djinn");
  set_long("This creature has the torso of a heavily-muscled man, though\n" +
	   "its lower body is a swirling mass of wind.\n");
  set_alias("djinn");
  set_level(8);
  set_ac(8);
  set_wc(9);
  set_hp(140 + random(40));
  set_ep(0);
  load_a_chat(50, ({
    "Djinn reaches back and throws a huge bare-fisted punch.\n",
    "Djinn swings its sword madly.\n"
  }));
  motion = "floats";
  bansp = 20;
  reqlevel = 8;
  msg = "Te arcesso de ventis elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
