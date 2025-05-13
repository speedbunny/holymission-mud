inherit "obj/monster";

#include "/players/matt/defs.h"

object sword;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  if(!sword) {
    sword = clone_object("players/matt/guild/objects/flamesword");
    MOVE(sword, TO);
             }
  set_name("fire priest");
  set_alias("priest");
  set_short("A red-robed priest");
  set_long("A man dressed in flame-red robes standing silently in the\n" +
	   "middle of the room. You could probably talk to him.\n");
  set_race("human");
  set_gender(1);
  set_level(1);
  set_no_fight(1);
  set_prevent_poison(1);
}

init() {
  ::init();
  add_action("talk", "talk");
  add_action("ask", "ask");
  add_action("give", "give");
}

talk(arg) {
  if(arg == "to priest") {
    if(present("flamesword", TO)) {
      write("You talk to the priest.\n");
      say(TP->NAME + " talks to the priest.\n");
      TELLR(ENV(TO), "Priest says: My sword will destroy any creature.\n");
      TELLR(ENV(TO), "Priest says: It is a most powerful weapon.\n");
      TELLR(ENV(TO), "Priest says: If you want to borrow it, just ask.\n");
      return 1;
    }
    write("The priest does not respond.\n");
    return 1;
  }
  write("Talk to whom?\n");
  return 1;
}

ask(arg) {
  if(arg == "for sword" || arg == "for flaming sword" ||
     arg == "priest for sword" ||
     arg == "priest for flaming sword") {
    if(present("flamesword", TO)) {
      write("You ask the priest for the sword.\n");
      say(TP->NAME + " asks the priest for his sword.\n");
      TELLR(ENV(TO), "Priest says: You may borrow my sword.\n");
      write("The priest gives you his sword.\n");
      say("Priest gives sword to " + TP->NAME + ".\n");
      MOVE(sword, TP);
      return 1;
    }
    write("The priest does not have that.\n");
    return 1;
  }
}

give(arg) {
  if(arg == "sword to priest" ||
     arg == "flaming sword to priest") {
    if(present("flamesword", TP)) {
      if(ENV(TO)->query_killed()) {
	write("You give the sword to the priest.\n");
	say(TP->NAME + " gives sword to priest.\n");
	TELLR(ENV(TO), "The priest disappears.\n");
	ENV(TO)->success();
	if(sword) destruct(sword);
	destruct(TO);
	return 1;
      }
      write("You give the sword to the priest.\n");
      say(TP->NAME + " gives sword to priest.\n");
      TELLR(ENV(TO), "The priest disappears.\n");
      if(sword) destruct(sword);
      destruct(TO);
      return 1;
    }
    write("You are not carrying that.\n");
    return 1;
  }
}

hit_player(arg) {
  object att;
  att = TO->query_attack();
  if(att && present(att, ENV(TO))) {
    TELLR(ENV(TO), "The figure says: Attack me not, Mortal.\n");
    return 1;
  }
  return 1;
}
