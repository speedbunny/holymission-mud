#include "func.c"

object mon;
int cost, heal;
string *blah;

status do_spell_checks(string args, object *soul, string file) {
  int sz;

  if (!args) {
    write("Syntax: cast cure <type> wounds <on <player>>\n");
    return (1);
  }

  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz < 2 || sz ==3 || sz > 4) {
    write("Syntax: cast cure <type> wounds <on <player>>\n");
    return (1);
  }
  if ((blah[0] != "light" && blah[0] != "serious" && blah[0] !="critical") ||
      (blah[1] != "wounds") || (sz == 4 && blah[2] != "on")) {
    write("Syntax: cast cure <type> wounds <on <player>>\n");
    return (1);
  }
  mon = sz == 4 ? PRES(blah[3], ENV(TP)) : TP;
  if (!mon) {
    printf("Cure %s wounds for who??\n", blah[0]);
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  cost = INFO->get_cost("cure " + blah[0]);
  if (CHECK(cost, INFO->get_level("cure " + blah[0])))
    return (1);

  switch (blah[0]) {
    case "light"    : heal = 2 * (random(40) + 1) + LVL(TP); break;
    case "serious"  : heal = 4 * (random(40) + 1) + LVL(TP); break;
    case "critical" : heal = 6 * (random(40) + 1) + LVL(TP); break;
  }
  if (!TIME("cure " + blah[0], soul, file)) return (1);
  return (1);
}

status do_spell() {
  int hp, mhp;
  if (mon == TP) {
    printf("You cast cure %s wounds on yourself.\n", blah[0]);
    say(NAME(TP) + " casts cure " + blah[0] + " wounds on " +
      OBJE(TP) + "self.\n");
  }
  else {
    printf("You cast cure %s wounds on %s.\n", blah[0], NAME(mon));
    say(NAME(TP) + " casts cure " + blah[0] + " wounds on" + NAME(mon) + ".\n");
    TELL(mon, NAME(TP) + " casts cure " + blah[0] + " wounds on you.\n");
  }
  mon->reduce_hit_point(-heal);
  hp = mon->query_hp();
  mhp = mon->query_max_hp();
  if (hp > mhp)
    mon->reduce_hit_point(hp - mhp);
  REDSP(cost);
  return (1);
}
