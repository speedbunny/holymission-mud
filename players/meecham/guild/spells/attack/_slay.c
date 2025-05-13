#include "func.c"
#define SN "slay living"
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
    write("Syntax: cast slay living <monster>\n");
    return (1);
  }
 
  blah = explode(args, " ");
  sz = sizeof(blah);
  if (sz < 1 || sz > 2) {
    write("Syntax: cast slay living <monster>>\n");
    return (1);
  }
  
  mon = sz == 2 ? PRES(blah[1], ENV(TP)) : TPA;
  if (!mon) {
    write("Slay who??\n");
    return (1);
  }
  if (!living(mon) || mon == TP) {
    write("Doh, don't be an idiot.\n");
    return (1);
  }
  
  mn = lower_case(NAME(mon));
  if (!TIME(SN, soul, file)) return (1);
  return (1);
}
 
status do_spell() {
  int lvl;
  string name;

  if (NF_ROOM(ENV(TP))) return (1);
  if (!mon) {
    printf("Strange, %s doesn't seem to be with us any longer.\n", mn);
    return (1);
  }
  if (!MON_STILL_HERE(mon)) return (1);
  printf("You attempt to slay %s!\n", NAME(mon));
  say(NAME(TP) + " attempts to slay " + NAME(mon) + "!\n");
  TELL(mon, NAME(TP) + "attempts to slay you!\n");
  lvl = LLVL(TP);
  name = NAME(mon);
  // heh, this assumes no one makes lglev 20 b4 we do away with them
  mon->hit_player((mon->query_hp() * lvl / 5) / 5 + lvl *75, 7);
  if (!mon || !random(100 - lvl)) {  
    write("\nYou are successful!\n");
    TELL(ENV(TP), name + " is SLAIN!\n");
    if (mon)
      mon->hit_player(100000 + mon->query_ac(), 7);
  }
  REDSP(cost);
  return (1);
}
