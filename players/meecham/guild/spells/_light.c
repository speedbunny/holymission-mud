#include "func.c"
#define SN "light" 
int cost;
 
status do_spell_checks(string args, object *soul, string file) {
 
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  if (present("druid_globe", TP)) {
    write("You already have a globe of light!\n");
    return (1);
  }

  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  object ob;

  write("You create a globe of light.\n"); 
  say(NAME(TP) + " creates a globe of light.\n");

  ob = CO(OBJ + "globe");
  ob->set_name("druid_globe");
  ob->set_alias("globe");
  ob->set_short("globe of light");
  ob->set_long("A Globe emitting warm, dim light.\n");
  ob->set_weight(0);
  ob->set_llevel(1);
  if (transfer(ob,TP)) {
    write("Something has gone wrong!\n");
    destruct(ob);
    return (1);
  }
  ob->set_time(600);
  if (ob->light(1) == 1) 
    TELL(ENV(TP),"You can see again.\n");
  REDSP(cost);
  return (1);
}
