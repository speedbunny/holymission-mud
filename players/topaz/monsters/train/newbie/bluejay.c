inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Blue Jay");
    set_alt_name("blue jay");
    set_alias("jay");
    set_race("avian");
    short_desc="A bright Blue Jay";
    long_desc="A bright Blue Jay, whistling a tune.\n";
    set_aggressive(0);
    set_level(2);
    set_ac(1);
    set_al(75);
  }
  return 1;
}
