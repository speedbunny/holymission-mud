#include "/players/redsexy/guild/guilddefs.h"

#define DART_DAM 20
#define MAX_DARTS 10

int numdarts, thrown;

id(arg) {
  if(numdarts == 1) return arg == "dart" || arg == "small dart";
  return arg == "darts" || arg == "small darts";
}

short() {
  if(numdarts == 1) return "A small dart";
  return numdarts + " small darts";
}

long() {
  if(numdarts == 1) write("A small dart.\n");
  else write("This is a set of " + numdarts + " small darts.\n");
  write("Just type \"throw dart\" to use in battle.\n");
  write("If you have more than one set, type \"gather darts\".\n");
}

get() { return 1; }

reset(arg) {
  if(arg) return;
  numdarts = MAX_DARTS;
}

init() {
  add_action("throw", "throw");
  add_action("gather", "gather");
}

throw(arg) {
  object att;
  if(id(arg) || arg == "dart") {
    att = TP->query_attack();
    if(att && present(att, ENV(TP))) {
      if(!thrown) {
	write("You throw a dart at " + att->NAME + ".\n");
	TELL(att, TP->NAME + " throws a dart at you!\n");
	say(TP->NAME + " throws a dart at " + att->NAME + ".\n", att);
	att->HIT(DART_DAM);
	numdarts--;
	thrown = 1;
	if(numdarts == 0) destruct(TO);
	else call_out("restore", 1);
	return 1;
      }
      write("You need to take time to aim properly.\n");
      return 1;
    }
    write("You are not attacking anyone.\n");
    return 1;
  }
}

gather(arg) {
  int i;
  object inv;
  if(arg == "darts") {
    if(ENV(TO) != TP) return;
    write("You gather up all your darts into one bunch.\n");
    say(TP->NAME + " gathers up " + TP->POS + " darts.\n");
    inv = all_inventory(TP);
    for(i = 0; i < sizeof(inv); i++)
      if((inv[i]->NAME == "dart" || inv[i]->NAME == "darts") &&
	 inv[i]->query_numdarts() && (inv[i] != TO)) {
	numdarts += inv[i]->query_numdarts();
	destruct(inv[i]);
      }
    return 1;
  }
}

restore() {
  thrown = 0;
  return 1;
}

query_name() {
  if(numdarts == 1) return "dart";
  return "darts";
}
query_value() { return 300 * (numdarts / MAX_DARTS); }
query_weight() { return 1; }
query_numdarts() { return numdarts; }
