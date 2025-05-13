#include "func.c"
#define SN "earthquake" 
int cost;
 
status do_spell_checks(string args, object *soul, string file) {
  object *ob;
  status yes;
  int i, j;

  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  yes = 0;
  ob = all_inventory(ENV(TP));
  i = sizeof(ob);
  for (j = 0; j < i; j++)
    if (living(ob[j]) && ob[j] != TP)
      yes = 1;
  if (!yes) {
    write("But you are the only living creature in the room!\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  object *ob;
  int i, j, lvl;

  if (NF_ROOM(ENV(TP))) return (1);
  tell_room(ENV(TP), "The room starts to shudder and suddenly a massive " +
    "earthquake\nerupts throughout the area!\n");
  // recalculate livings due to heartbeat delay *shrug*
  lvl = LVL(TP) > 20 ? 20 : LVL(TP);
  ob = all_inventory(ENV(TP));
  i = sizeof(ob);
  for (j = 0; j < i; j++)
    if (living(ob[j]) && ob[j] != TP && !TP->query_party_member(ob[j])) {
      printf("%s is sent flying across the room!\n", NAME(ob[j]));
      ob[j]->hit_player(lvl * (random(20) + 1));
      if (ob[j])
        TELL(ob[j], "An earthquake sends you flying across the room!\n");
    } 
  REDSP(cost);
  return (1);
}
