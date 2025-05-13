inherit "obj/monster";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"

status calmed, berzerk, ter;
int bansp, reqlevel;
string motion, msg, sname;
object att, otherattack, master;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("attacker");
  set_level(1);
  set_ep(0);
  set_dead_ob(TO);
}

init() {
  ::init();
  if(!master || master->query_ghost()) destroy_me(1);
  add_action("catt",  "catt");
  add_action("cstop", "cstop");
  add_action("cter",  "cter");
  add_action("ban",   "ban");
}

heart_beat() {
  att = master->query_attack();
  if(att && (ENV(att) == ENV(TO)) && !berzerk && !calmed &&
     (!otherattack || (ENV(otherattack) != ENV(TO)))) {
    TO->attack_object(att);
    TO->attack_object(att);
  }
  if(!att || !TO->query_attack()) {
    set_heart_beat(0);
    return;
  }
  ::heart_beat();
}

catt(arg) {
  object target;
  if(TP != master) return;
  if(arg) {
    if(berzerk) {
      write("You cannot control the " + TO->NAME + "!\n");
      return 1;
    }
    target = present(arg, ENV(TP));
    if(target) {
      if(living(target)) {
	if(target->query_attack() == TP ||
	   TP->query_attack() == target) {
	  CHECK_INTOX();
	  CHECK_ARM();
	  CHECK_WEAP();
	  CHECK_SP(ATT_ATK_SP);
	  write("You command your " + TO->NAME + " to attack " +
		target->NAME + ".\n");
	  say(TP->NAME + " speaks a word of command.\n");
	  TELL(target, SHORT + " turns to attack you.\n");
	  TELLS(SHORT + " turns to attack" + target->NAME +
		".\n", TP, target);
	  TO->attack_object(target);
	  otherattack = target;
	  calmed = 0;
	  return 1;
	}
	write("You are not engaged in combat with " + target->NAME +
	      ".\n");
	return 1;
      }
      write("Your " + TO->NAME + " cannot attack " + CAP(arg) +
	    ".\n");
      return 1;
    }
    write("Your " + TO->NAME + " cannot find " + CAP(arg) + ".\n");
    return 1;
  }
  write("Syntax: catt <monster>\n");
  return 1;
}

cstop(arg) {
  object att;
  if(TP != master) return;
  if(!arg) {
    if(berzerk) {
      write("You cannot control the " + TO->NAME + "!\n");
      return 1;
    }
    att = TO->query_attack();
    if(att && (ENV(att) == ENV(TO))) {
      CHECK_INTOX();
      CHECK_ARM();
      CHECK_WEAP();
      CHECK_SP(ATT_ATK_SP);
      write("You command your " + TO->NAME + " to stop fighting.\n");
      say(TP->NAME + " speaks a word of command.\n");
      say(TO->SHORT + " stops fighting.\n");
      att->stop_fight();
      att->stop_fight();
      att->stop_hunter(1);
      TO->stop_fight();
      TO->stop_fight();
      TO->stop_hunter(1);
      otherattack = 0;
      calmed = 1;
      return 1;
    }
    write("Your " + TO->NAME + " is not fighting.\n");
    return 1;
  }
  write("Syntax: cstop\n");
  return 1;
}

cter(arg) {
  object target;
  if(TP != master) return;
  if(arg) {
    if(berzerk) {
      write("You cannot control the " + TO->NAME + "!\n");
      return 1;
    }
    if(ter) { 
      target = present(arg, ENV(TP));
      if(target) {
	if(living(target)) {
	  if(target->query_attack() == TP ||
	     TP->query_attack() == target) {
	    CHECK_INTOX();
	    CHECK_ARM();
	    CHECK_WEAP();
	    CHECK_SP(ATT_TER_SP);
	    write("You command your " + TO->NAME + " to unleash " +
		  "its terrible aura on " + target->NAME + ".\n");
	    say(TP->NAME + " speaks a word of command.\n");
	    TELL(target, "You are suddenly uncontrollably terrified by " +
		 SHORT + "!\n");
	    say(target->NAME + " is uncontrollably terrified by " +
		TO->SHORT + "\n", target);
	    target->run_away();
	    calmed = 0;
	    return 1;
	  }
	  write("You are not engaged in combat with " + target->NAME +
		".\n");
	  return 1;
	}
	write("Your " + TO->NAME + " cannot terrify " + CAP(arg) +
	      ".\n");
	return 1;
      }
      write("Your " + TO->NAME + " cannot find " + CAP(arg) + ".\n");
      return 1;
    }
    write("Your " + TO->NAME + " does not have that ability.\n");
    return 1;
  }
  write("Syntax: cter <monster>\n");
  return 1;
}

ban(arg) {
  if(TP != master) return;
  if(id(arg)) {
    if(berzerk) {
      write("You cannot control the " + TO->NAME + "!\n");
      return 1;
    }
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(bansp);
    write("You draw a circle in the dust and command your " +
	  TO->NAME + " to enter it.\n");
    write("It " + motion + " into the circle and " +
	  "vanishes.\n");
    say(TP->SNAME + " draws a circle on the ground with his finger " +
	"and traces\n");
    say("Runes of power around it.\n");
    say(CAP(TP->PRO) + " gestures towards " + TP->POS + " " +
	TO->NAME + " and commands:\n");
    say("'Circulum intra!'\n");
    say("It " + motion + " into the circle and " +
	"vanishes\n");
    say("from this Plane in a flash of light.\n");
    destroy_me(1);
    return 1;
  }
}

make_me(obj, num) {
  master = obj;
  setup();
  write("You chant words of power as your draw the circle " +
	"and trace\n");
  write("out magical Runes in the air.\n");
  write("A blinding light flashes from within the circle as the " +
	TO->NAME + "\n");
  write("is gated in.\n");
  write("It " + motion + " out of the circle " +
       "towards you.\n");
  say(master->SNAME + " draws a circle on the ground with " + master->POS +
      " finger, chanting\n");
  say("words of Power as " + master->PRO + " traces out mystic " +
      "Runes.\n");
  say("\"" + msg + ".\"\n");
  say("There is a swirl of blinding light from within the circle " +
      "as a\n");
  say("shimmering form is gated into existence.\n");
  say("A powerful " + TO->NAME + " " + motion + " out of the " +
      "circle\n");
  say("towards " + master->SNAME + ".\n");
  if((master->LEVEL >= reqlevel) ||
     (random(100) < (SUCCESS / reqlevel))) {
    write("It bows its head in submission, bound by your " +
	  "strength of will.\n");
    say("It bows its head in submission, bound by " + master->SNAME +
	"'s strength of will.\n");
  }
  else {
    write("You lose your concentration.\n");
    write("The " + TO->NAME + " rips free of its bonds and " +
	 "turns to attack you!\n");
    say("For a split second, " + master->PRO + " loses " +
	master->POS + " concentration.\n");
    say("The " + TO->NAME + " rips free of its magical bonds " +
	"and roars in an\n");
    say("otherworldly tongue as it turns to attack " +
	master->OBJ + ".\n");
    TO->attack_object(master);
    berzerk = 1;
  }
  return 1;
}

beat(arg) { set_heart_beat(arg); }

move_me(silent) {
  if(ENV(TO) != ENV(master)) {
    if(!silent)
      TELLRS(ENV(TO), SHORT + " " + motion +
	     " after " + master->OBJ + ".\n", master, TO);
    MOVE(TO, ENV(master));
    if(!silent) {
      TELL(master, "Your " + TO->NAME + " " + motion + " in.\n");
      say(SHORT + " " + motion + " in.\n", master);
    }
  }
  return 1;
}

destroy_me(silent) {
  if(!silent) {
    if(master) TELL(master, "Your " + TO->NAME + " vanishes.\n");
    TELLRS(ENV(TO), SHORT + " vanishes.\n", master, TO);
  }
  destruct(TO);
  return 1;
}

monster_died() {
  if(!present(master, ENV(TO))) 
    TELL(master, "Your " + TO->NAME + " dies.\n");
  say("The spirit of " + TO->SHORT + " rises towards the sky\n" +
      "and vanishes, leaving no material corpse on this Plane.\n", master);
  destroy_me(1);
  return 1;
}

grmems_in_room() {
  if(master) return ({ master });
  return ({ TO });
}

query_calmed() { return calmed; }
query_show_short() { return 1; }
query_creature() { return "attacker"; }
