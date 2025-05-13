#include "func.c"
#define SN "flameblade" 
int cost;
 
status do_spell_checks(string args, object *soul, string file) {
 
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  if (present("Flame_Blade", TP)) {
    write("The one you have will do just fine.\n");
    return (1);
  }

  if (TP->query_wielded()) {
    write("You cannot be wielding a weapon when you cast this spell.\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  object fb;

  write("You create a flaming blade.\n"); 
  say(NAME(TP) + " pulls a flaming blade from the air!\n");
  fb = CO(OBJ + "flameblade");
  if (transfer(fb, TP)) {
    write("You are unable to carry the blade and abort your spell.\n");
    return (1);
  }
  fb->set_level(LLVL(TP) ? LVL(TP) + LLVL(TP) : LVL(TP));  
  REDSP(cost);
  return (1);
}
