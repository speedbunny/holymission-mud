#include "func.c"

object mon;
int cost, damage;
string *blah,mn;

status do_spell_checks(string args, object *soul, string file) {
  int sz;

  if (!args) {
    write("Syntax: cast cause <type> wounds <on <monster>>\n");
    return (1);
  }

  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz < 2 || sz ==3 || sz > 4) {
    write("Syntax: cast cause <type> wounds <on <monster>>\n");
    return (1);
  }
  if ((blah[0] != "light" && blah[0] != "serious" && blah[0] != "critical") ||
      (blah[1] != "wounds") || (sz == 4 && blah[2] != "on")) {
    write("Syntax: cast cause <type> wounds <on <monster>>\n");
    return (1);
  }
  mon = sz == 4 ? PRES(blah[3], ENV(TP)) : TPA;
  if (!mon) {
    printf("Cause %s wounds on who??\n", blah[0]);
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  cost = INFO->get_cost("cause " + blah[0]);
  if (CHECK(cost, INFO->get_level("cause " + blah[0])))
    return (1);

  switch (blah[0]) {
    case "light"    : damage = 2 * (random(40) + 1) + LVL(TP); break;
    case "serious"  : damage = 4 * (random(40) + 1) + LVL(TP); break;
    case "critical" : damage = 6 * (random(40) + 1) + LVL(TP); break;
  }
  mn = lower_case(NAME(mon));
  if (!TIME("cause " + blah[0], soul, file)) return (1);
  return (1);
}

status do_spell() {
  if (NF_ROOM(ENV(TP))) return (1);
  if (!mon) {
    printf("Strange, %s doesn't seem to be with us any longer.\n", mn);
    return (1);
  }
  if (!MON_STILL_HERE(mon)) return (1);
  printf("You cast cause %s wounds at %s.\n", blah[0], NAME(mon));
  say(NAME(TP) + " casts cause " + blah[0] + " wounds at " + NAME(mon) + ".\n");
  TELL(mon, NAME(TP) + " casts cause " + blah[0] + " wounds at you!\n");
  mon->hit_player(damage);
  REDSP(cost);
  return (1);
}
