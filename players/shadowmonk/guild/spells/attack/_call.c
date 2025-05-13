#include "func.c"
#define SN "call lightning"
int cost;
object mon;
string mn;

status do_spell_checks(string args, object *soul, string file) {
  string *str;

  str = explode(args, " ");
  if (str[0] != "lightning") return (0);
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);

  mon = (sizeof(str) > 1) ? PRES(str[1], ENV(TP)) : TPA;
  if (!mon) {
    write("Call lightning on who??\n");
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }

  mn = lower_case(NAME(mon));
  if (!TIME(SN, soul, file)) return (1);
  return (1);
}

status do_spell() {
  int lvl;

  if (NF_ROOM(ENV(TP))) return (1);
  if (!mon) {
    printf("Strange, %s doesn't seem to be with us any longer.\n", mn);
    return (1);
  }
  if (!MON_STILL_HERE(mon)) return (1);
  printf("You call to the heavens and a lightning bolt crashes down on\n" +
    "%s!\n", NAME(mon));
  say(NAME(TP) + " calls a lightning bolt down upon " + NAME(mon) + "!\n");
  TELL(mon, NAME(TP) + " calls a lightning bolt down on you!\n");
  lvl = LVL(TP) > 20 ? 20 : LVL(TP);
  mon->hit_player(lvl * (random(20) + 1));
  REDSP(cost);
  return (1);
}
