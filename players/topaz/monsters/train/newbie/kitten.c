inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Kitten");
    set_alt_name("kitten");
    set_race("feline");
    short_desc="A cute little kitten";
    long_desc="A cute little kitten, purring happily.\n";
    set_aggressive(0);
    set_level(1);
    set_ac(1);
    set_al(100);
  }
  return 1;
}
