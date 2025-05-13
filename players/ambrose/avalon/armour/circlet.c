#include "/spells/spell.h"
inherit "obj/armour";

reset(arg){
if(arg);

  set_name("circlet");
  set_short("Silver Circlet");
  set_long("This silver circlet fits snugly on you head.  With it in place\n"+
           "you thoughts seem to race.  Everything is much clearer and makes\n"+
           "sense.\n");
  set_value(3000);
  set_type("helmet");
  set_size("medium");
  set_ac(0);
  modify_stat(3,3);
}
