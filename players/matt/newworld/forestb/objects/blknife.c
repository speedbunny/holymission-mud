inherit "/obj/weapon";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("knife");
  set_alias("black knife");
  set_short("Black knife");
  set_long("A long blackened knife made of hard-tempered metal.\n" +
	   "It looks like it could cut through anything.\n");
  set_class(8);
  set_value(500);
}
     
drop() {
  write("You drop the knife. It disappears.\n");
  say(TP->SNAME + " drops knife. It disappears.\n");
  TP->stop_wielding(TO);
  destruct(TO);
  return 1;
}
