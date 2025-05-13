#include "func.c"
#define SN "create"
int cost;

status do_spell_checks(string args, object *soul, string file) {

  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);

  if (present("band", this_player())) {
    write("Nah, one is enough.\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}

status do_spell() {
  object hb;

  write("You kneel down and and ask mother nature for a gift.\n");
  say(NAME(TP) + " kneels down and asks mother nature for a gift.\n");
  hb = CO(OBJ + "headband");
  if (transfer(hb, TP)) {
    write("You cannot seem to accept mother nature's gift.\n");
    say(NAME(TP) + " cannot accept mother nature's gift.\n");
    return (1);
  }
  write("You receive a headband.\n");
  say(NAME(TP) + " receives a headband.\n");
  REDSP(cost);
  return (1);
}
