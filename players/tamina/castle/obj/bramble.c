inherit "obj/thing";

#include "/players/tamina/defs.h"

#define HEAL_ME 10

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bramble");
  set_short("A Bramble");
  set_long("A plump little bramble.\n");
  set_value(60);
  set_weight(1);
}

id (str)
{
  return str == name || str == "a bramble" || str == "the bramble";
}

init() {
  ::init();
  add_action("_eat", "eat");
}

int _eat(string str) 
{

  if (!id(str)) 
  {
    NFAIL("Eat what?\n");
    return 0;
  }
  else
  {
    write("You pop the tasty, juicy bramble into your mouth.  Mmmmmm\n");
    say(TPN+" pulls a face as "+TP->QPRO+" eats a sour bramble!\n");
    
    if((TP->MAXHP - TP->HP) < HEAL_ME)
      TP->ADDHP(TP->MAXHP - TP->HP);
    else TP->ADDHP(HEAL_ME);

    if((TP->MAXSP - TP->SP) < HEAL_ME)
      TP->ADDSP(TP->MAXSP - TP->SP);
    else TP->ADDSP(HEAL_ME);
    
    destruct(TO);
    
    return 1;
  }
}
