inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Blob");
    set_alias("blob");
    set_alt_name("the blob");
    set_race("monster");
    short_desc="A lumpy blob";
    long_desc="An ugly, lumpy blob.\n" +
              "It looks really pathetic.\n";
    set_aggressive(1);
    set_level(2);
    set_wc(6);
    set_ac(1);
    set_al(-150);
    set_hp(200);
  }
  return 1;
}
