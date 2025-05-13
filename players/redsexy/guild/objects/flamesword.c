inherit "obj/weapon";

#include "/players/redsexy/defs.h"

#define MAGE 5

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("flamesword");
  set_short("Flaming sword");
  set_long("Hot tongues of flame eminate from this sword's blade. You\n" +
	   "sense that this weapon is one of the most powerful known\n" +
	   "to mortals.\n");
  set_alias("sword");
  set_class(20);
  set_value(50000);
  set_weight(0);
}

wield(arg) {
  if(TP->query_guild() == MAGE)
    set_class(5);
  ::wield(arg);
  return 1;
}
