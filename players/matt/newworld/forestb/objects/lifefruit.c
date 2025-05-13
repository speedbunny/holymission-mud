inherit "/obj/thing";

#include "/players/matt/defs.h"

#define HEAL 100;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("golden fruit");
  set_alias("fruit");
  set_short("Golden fruit");
  set_long("A luscious, shiny piece of golden fruit that makes your mouth\n" +
	   "water when you look at it.\n");
  set_weight(1);
  set_value(1000);
}

init() {
  ::init();
  add_action("eat", "eat");
}

drop() {
  write("The golden fruit crumbles as you drop it.\n");
  say("A piece of golden fruit crumbles as " + TP->SNAME + " drops it.\n");
  destruct(TO);
  return 1;
}

eat(arg) {
  int temp;
  if(id(arg)) {
    temp = HEAL;
    if((TP->MAXHP - TP->HP) < temp) temp = (TP->MAXHP - TP->HP);
    TP->ADDHP(temp);
    temp = HEAL;
    if((TP->MAXSP - TP->SP) < temp) temp = (TP->MAXSP - TP->SP);
    TP->ADDSP(temp);
    write("You crunch into the juicy golden fruit, and eat it hungrily.\n");
    write("You feel much better.\n");
    say(TP->NAME + " eats the golden fruit.\n");
    destruct(TO);
    return 1;
  }
}
