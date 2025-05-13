inherit "/obj/thing";

#include "/players/matt/defs.h"

#define HEAL_AMT 20

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cheese");
  set_short("A bit of cheese");
  set_long("A tiny bit of cheese which, though small, looks delicious.\n");
  set_value(100);
  set_weight(1);
}

init() {
  ::init();
  add_action("eat", "eat");
}

eat(arg) {
  if(id(arg)) {
    write("You munch on the cheese. It tastes good!\n");
    say(TP->NAME + " munches on some cheese.\n");
    if((TP->MAXHP - TP->HP) < HEAL_AMT)
      TP->ADDHP(TP->MAXHP - TP->HP);
    else TP->ADDHP(HEAL_AMT);
    if((TP->MAXSP - TP->SP) < HEAL_AMT)
      TP->ADDSP(TP->MAXSP - TP->SP);
    else TP->ADDSP(HEAL_AMT);
    destruct(TO);
    return 1;
  }
}
