#include "func.c"
#define SN "remove poison" 
int cost;
object mon;
 
status do_spell_checks(string args, object *soul, string file) {
  int sz;
  string *blah;

  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  if (!args) {
    write("Syntax: cast remove poison <for <player>>\n");
    return (1);
  }

  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz < 1 || sz == 2 || sz > 3) {
    write("Syntax: cast remove poison <for <player>>\n");
    return (1);
  }

  mon = sz == 3 ? PRES(blah[2], ENV(TP)) : TP;
  if (!mon) {
    write("Remove poison for who??\n");
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  if (!living(mon) || mon->query_npc()) {
    write("Doh, don't be an idiot.\n");
    return (1);  
  }
  
  if (!mon->query_poisoned()) {
    write("This spell is bast saved for someone who is actually poisoned...\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  if (mon == TP) { 
    write("You don't feel as poisoned anymore.\n");
    say(NAME(TP) + " doesn't look as sickly anymore.\n");
  } else {
    printf("You cast remove poison on %s.\n", NAME(mon));
    TELL(mon, NAME(TP) + " casts remove poison on you.\n" +
      "You don't feel as poisoned anymore.\n");
  }
  mon->add_poison(-100);
  REDSP(cost);
  return (1);
}
