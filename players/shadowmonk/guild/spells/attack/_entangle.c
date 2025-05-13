#include "func.c"
#define SN "entangle"
int cost;
object mon;
string mn;

status do_spell_checks(string args, object *soul, string file) {

  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);

  mon = args ? PRES(args, ENV(TP)) : TPA;
  if (!mon) {
    write("Entangle who?\n");
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  if (mon->entangle_shad()) {
    printf("%s is already entangled!\n", NAME(mon));
    return (1);
  }

  mn = lower_case(NAME(mon));
  if (!TIME(SN, soul, file)) return (1);
  return (1);
}

status do_spell() {
  object shad;
  int level;

  if (NF_ROOM(ENV(TP))) return (1);
  if (!mon) {
    printf("Strange, %s doesn't seem to be with us any longer.\n", mn);
    return (1);
  }
  if (!MON_STILL_HERE(mon)) return (1);
  printf("You utter magic and tangle vines grow up around the body\n" +
    "of %s!\n", NAME(mon));
  say(NAME(TP) + " causes tangle vines to trap " + NAME(mon) + "!\n");
  TELL(mon, NAME(TP) +" entangles you in tangle vines!\n");
  shad = CO(OBJ + "entangle_shad");
  shad->set_owner(mon);
  level = LLVL(TP) ? LVL(TP) + LLVL(TP) : LVL(TP);
  shad->start(level);
  TP->attack_object(mon);
  REDSP(cost);
  return (1);
}
