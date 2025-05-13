inherit "obj/monster";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("guardian");
  set_short("A hideous Guardian");
  set_long("This infernal creature has been gated to this Plane by the\n" +
	   "most powerful of Summoners to guard their sacred Guild from\n" +
	   "unwanted outsiders. Its huge twelve-foot-tall Material form\n" +
	   "suggests that it would be very unwise to attack it.\n");
  set_race("demon");
  set_level(100);
  set_al(-1000);
  set_no_fight(1);
  set_prevent_poison(1);
}

hit_player(arg) {
  int i;
  object att, inv;
  att = TO->query_attack();
  if(att && present(att, ENV(TO))) {
    inv = all_inventory(ENV(TO));
    TELLR(ENV(TO), "The Guardian screams: You dare attack me?\n");
    TELLR(att, "A bolt of hellfire strikes you!\n");
    for(i = 0; i < sizeof(inv); i++) {
      if(inv[i] != att) TELL(inv[i], "A bolt of hellfire " +
			     "strikes " + TP->NAME + "!\n");
    }
    TP->ADDHP(TP->HP / -2);
    return 1;
  }
  return 1;
}
