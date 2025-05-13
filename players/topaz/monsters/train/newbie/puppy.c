inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Puppy");
    set_alt_name("puppy");
    set_race("canine");
    short_desc="A playful puppy";
    long_desc="A cute puppy, chasing it's tail.\n";
    set_aggressive(0);
    set_level(3);
    set_ac(2);
    set_al(100);
  }
  return 1;
}
