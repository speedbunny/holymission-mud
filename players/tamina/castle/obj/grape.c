inherit "obj/thing";

#include "/players/tamina/defs.h"

#define HEAL_ME 20

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("grape");
  set_short("A Grape");
  set_long("A juicy grape.\n");
  set_value(100);
  set_weight(1);
}

id (str)
{
  return str == name || str == "a grape" || str == "the grape";
}

init() 
{
  ::init();
  add_action("_eat", "eat");
}

int _eat (string str) {

  if (!id(str)) 
  {
    NFAIL("Eat what?\n");
    return 0;
  }
  else
  {
    write("You pop the tasty, juicy grape into your mouth.  Mmmmmm\n");
    say(TPN+" gorges on a grape!\n");
    
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
