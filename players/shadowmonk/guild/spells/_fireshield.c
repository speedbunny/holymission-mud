#include "func.c"
#define SN "fireshield" 
int cost;
object mon;
 
status do_spell_checks(string args, object *soul, string file) {
 
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  mon = args ? present(args, ENV(TP)) : TP;
  if (!mon) {
    write("Fireshield who?\n");
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  if (mon->query_npc()) {
    write("Sorry, no fireshielding monsters.\n");
    return (1);
  }
  if (mon->fireshield()) {
    printf("%s is already fireshielded!\n", NAME(mon));
    return (1);
  }
  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  object shad; 
  
  if (mon != TP) {
    TELL(mon,"Flames leap to life and surround your body.\n");
    printf("You cast fireshield on %s.\n", NAME(mon));
  } else 
    write("Flames leap to life and surround your body.\n");
  say("Flames leap to life and surround " + NAME(mon) + "'s body.\n");
  if (mon->bark_shadow()) {
    mon->stop_bark_shad();
    TELL(mon, "The flames burn away your barkskin!\n");
  }
  shad = CO(OBJ + "fshield_shad");
  shad->set_owner(mon);
  shad->start();
  REDSP(cost);
  return (1);
}
