
inherit "/obj/weapon";

#include "/players/morningsir/defs.h"

reset(arg) {
  ::reset();
  if (arg) return;

  set_name("scythe");
  set_alias("scythe");
  set_alt_name("scythe");
  set_short("The scythe of The Death Warrior");
  set_long("The scythe of The Death Warrior must be a deadly weapon even for the wielder.\n");
  set_read("There is dried blood everywhere but you can make out the word: 'DIE'.\n");

  set_class(19);
  set_weight(5);
  set_value(3000);

  set_hit_func(TO);
  set_wield_func(TO);
}

weapon_hit(attacked) {
  if (attacked->query_level() < 30) {
    write("You watch as the scythe jumps at " + attacked->query_name() + "and rips\n" +
          attacked->query_possessive() + " head off.\n");
    say(TP->query_name() + "swings his scythe at " + attacked->query_name() + " and rips\n" +
        attacked->query_possessive() + " head off.\n");
    return ;
  }
  return 0;
}

wield(ob) {
/*
 * if (TP->query_level() < 30 && TP->query_name() != "death") {
 *   write("You are too mortal to wield the scythe of death.\n");
 *   say(TPN + " tries to wield the scythe of death but fails.\n");
 *   return 0;
 * }
 * write("The scythe creaks and screams but you tame it finally.\n");
 * if (TPN == "death") {
 *   say("The death warrior licks the blade of her scythe and starts to move.\n");
 * } else {
 *   say(TPN + " challenges the deadly scythe and succeeds.\n");
 * }
*/
	return 1;	/* 0 = not OK to wield, 1 = OK to wield */
}

