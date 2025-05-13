inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Bunny");
    set_alt_name("bunny");
    set_race("rabbit");
    short_desc="A soft looking bunny";
    long_desc="A soft looking, white bunny.\n";
    set_aggressive(0);
    set_level(1);
    set_ac(1);
    set_al(100);
  }
  return 1;
}
