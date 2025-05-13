#include "/players/saffrin/defs.h"
#define SN "unpoison" 
int cost;
object victim;
 
status do_spell_checks(string args, object *soul, string file) {
  int sz;
  string *blah;

  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  if (!args) {
    write("Syntax: unpoison or unpoison <player>\n");
    return (1);
  }

  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz < 1 || sz == 2 || sz > 3) {
    write("Syntax: unpoison or unpoison <player>\n");
    return (1);
  }

  victim = sz == 3 ? PRES(blah[2], ENV(TP)) : TP;
  if (!victim) {
    write("Who do you want to unpoison?\n");
    return (1);
  }
  if (!living(victim)) {
    write("You cannot unpoison that.\n");
    return (1);
  }
  if (!living(victim) || victim->query_npc()) {
    write("You cannot unpoison that.\n");
    return (1);  
  }
  
  if (!victim->query_poisoned()) {
    write("They are not poisoned.\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  if (victim == TP) { 
    write("You are no longer poisoned.\n");
    say(NAME(TP) + " is no longer poisoned.\n");
  } else {
    printf("You attempt to unpoison %s.\n", NAME(victim));
    TELL(victim, NAME(TP) + " attempts to unpoison you.\n" +
      "You are no longer poisoned.\n");
  }
  victim->add_poison(-100);
  REDSP(cost);
  return (1);
}
