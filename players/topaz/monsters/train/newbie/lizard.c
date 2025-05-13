inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Lizard");
    set_alt_name("lizard");
    set_race("reptile");
    short_desc="A small lizard";
    long_desc="A small lizard.\n" +
              "It seems to be enjoying the warmth of the rocks it is on.\n";
    set_aggressive(0);
    set_level(1);
    set_ac(2);
    set_al(50);
  }
  return 1;
}
