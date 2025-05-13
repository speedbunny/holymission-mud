#include "func.c"
#define SN "harm"
int cost;
object mon;
string mn;
 
status do_spell_checks(string args, object *soul, string file) {
 
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
 
  mon = args ? PRES(args, ENV(TP)) : TPA;
  if (!mon) {
    write("Harm who?\n");
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
  printf("Your touch sends %s reeling!\n", NAME(mon));
  say(NAME(TP) + "'s touch sends " + NAME(mon) + "reeling!\n");
  TELL(mon, NAME(TP) + ";s touch sends you reeling!\n");
  lvl = LLVL(TP) ? LVL(TP) + LLVL(TP) : LVL(TP);
  mon->hit_player(20 * (random(40) + 1) + (lvl * 3));
  REDSP(cost);
  return (1);
}
