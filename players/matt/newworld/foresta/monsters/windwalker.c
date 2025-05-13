inherit "/obj/monster";

#include "/players/matt/defs.h"

object wsword;

reset(arg) {
  ::reset(arg);
  if(!wsword) {
    wsword = clone_object(NWFORESTA + "objects/windsword");
    MOVE(wsword, TO);
  }
  if(arg) return;
  set_name("wind walker");
  set_short("Wind walker");
  set_long("An elemental creature from the Plane of Wind, this creature\n" +
	   "is very difficult to see.\n");
  set_alias("walker");
  set_race("elemental");
  set_level(20);
  set_hp(600);
  set_wc(12);
  set_ac(50);
  set_aggressive(1);
  set_chance(5);
  set_spell_mess1("The Wind Walker hurls a blast of wind!\n");
  set_spell_mess2("You are hit by a blast of wind!\n");
  set_spell_dam(50);
  add_money(1000);
}

init() {
  ::init();
  command("wield sword", TO);
}

hit_player(arg) {
  object att, weap;

  if(!random(20)) {
    att = TO->query_attack();
    if(att) {
      weap = att->query_wielded();
      if(weap) {
	TELL(att, weap->SHORT + " is sucked from your hands\n" +
	     "as it hits the Wind Walker!\n\n");
	say(att->NAME + "'s weapon is sucked out of " + att->POS +
	    " hands!\n", att);
	att->stop_wielding(weap);
        transfer(weap,environment(TO));
      }
    }
  }
  return ::hit_player(arg);
}
