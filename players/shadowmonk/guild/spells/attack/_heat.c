#include "func.c"
#define SN "heat armour" 
int cost;
object mon; 
string mn;

status do_spell_checks(string args, object *soul, string file) {
  int sz;
  string *blah;
  
  cost = INFO->get_cost(SN);
  if (CHECK(cost, INFO->get_level(SN)))
    return (1);
  
  if (!args) {
    write("Syntax: cast heat armour on <monster>\n");
    return (1);
  }

  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz != 3) { 
    write("Syntax: cast heat armour on <monster>\n");
    return (1);
  }
  mon = PRES(blah[2], ENV(TP));
  if (!mon) {
    write("Heat armour on who??\n");
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
  string *armor1, *armor2;                
  string target;
  int i, sz;              
  object shad;

  if (NF_ROOM(ENV(TP))) return (1);
  if (!mon) {
    printf("Strange, %s doesn't seem to be here any longer.\n");
    return (1);
  }
  if (!MON_STILL_HERE(mon)) return (1);
  armor2 = ({ });
  armor1 = mon->query_armour();
  sz = sizeof(armor1);
  for (i = sz - 1;i >= 0;i--)
    if (objectp(armor1[i]) && !armor1[i]->id("soul"))
      armor2 += ({ armor1[i] });
  i = sizeof(armor2);
  if (i) {
    target = armor2[random(i)];
    shad = CO(OBJ + "heat_a_shad");
    shad->set_owner(mon);
    shad->set_length((LLVL(TP) ? LLVL(TP) + LVL(TP) : LVL(TP)) / 2);
    shad->start();
    printf("You notice with pleasure as %s's %s starts glowing red.\n",
      NAME(mon), NAME(target));
    say(NAME(mon) + "'s " + target->query_name() + " starts glowing red.\n");
    REDSP(cost);
  } else 
    printf(NAME(mon) + " has no armour.\n");
  return (1);
}
