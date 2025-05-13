inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Cockroach");
    set_alt_name("cockroach");
    set_race("insect");
    short_desc="A large cockroach";
    long_desc="A big cockroach.\n" +
              "It is a disgusting creature.  It is filthy!\n";
    set_aggressive(1);
    set_level(3);
    set_ac(2);
    set_al(-100);
  }
  return 1;
}
