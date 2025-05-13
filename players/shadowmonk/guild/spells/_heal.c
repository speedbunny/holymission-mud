#include "func.c"
object mon;
int cost, heal;
string *blah;
 
status do_spell_checks(string args, object *soul, string file) {
  int sz;
 
  if (!args) {
    write("Syntax: cast heal <type> <player>\n");
    return (1);
  }
 
  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz < 1 || sz > 2) {
    write("Syntax: cast heal <type> <player>>\n");
    return (1);
  }
  if (blah[0] != "minor" && blah[0] != "major") {
    write("Syntax: cast <type> <player>\n");
    return (1);
  }
  
  mon = sz == 2 ? PRES(blah[1], ENV(TP)) : TP;
  if (!mon) {
    write("Heal who??\n");
    return (1);
  }
  if (!living(mon)) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  
  cost = INFO->get_cost("heal " + blah[0]);
  if (CHECK(cost, INFO->get_level("heal " + blah[0])))
    return (1);
 
  switch (blah[0]) {
    case "minor" : heal = 10 * (random(40) + 1) + 50; break;
    case "major" : heal = 10000;                      break;
  }
  if (!TIME("heal " + blah[0], soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  int hp, mhp;  
  if (mon == TP) {
    printf("You cast heal %s on yourself.\n", blah[0]);
    say(NAME(TP) + " casts heal " + blah[0] + " on " + PRO(TP) + ".\n");
  }
  else {
    printf("You cast heal %s on %s.\n", blah[0], NAME(mon));
    say(NAME(TP) + " casts heal " + blah[0] + " on" + NAME(mon) + ".\n");
    TELL(mon, NAME(TP) + " casts heal " + blah[0] + " on you.\n");
  }  
  mon->reduce_hit_point(-heal);
  hp = mon->query_hp();
  mhp = mon->query_max_hp();
  if (hp > mhp)
    mon->reduce_hit_point(hp - mhp);
  REDSP(cost);
  return (1);
}
