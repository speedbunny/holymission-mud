#include "/players/matt/guild/obdefs"
#include "/players/matt/guild/functions"

object master, creature;

make_me(player, attacker) {
  master = player;
  creature = attacker;
  shadow(master, 1);
  return 1;
}

hit_player(dam, type) {
  write(TP, "You hit " + creature->SHORT + ".\n");
  TELL(master, TP->SNAME + " hits your " + creature->NAME + ".\n");
  TELLRS(ENV(master), TP->SNAME + " hits " + creature->SHORT + ".\n",
	 master, TP);
  creature->HITP(dam, type);
  return master->HITP(dam, type);
}
