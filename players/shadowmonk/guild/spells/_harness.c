#include "func.c"
#define SN "harness wind" 
int cost;
 
status do_spell_checks(string args, object *soul, string file) {
 
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  if (ENV(TP)->query_property("no_teleport")) {
    write("You can't seem to harness any wind here.\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  write("You get swept up in a large gust of wind.\n");
  say(NAME(TP) + " gets swept up in a large gust of wind.\n");
  TP->move_player("on a gust of wind#players/shadowmonk/guild/room");
  REDSP(cost);
  return (1);
}
