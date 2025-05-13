inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("mace");
    short_desc="A heavy mace";
    long_desc="A compact, yet possibly deadly mace.\n";
    set_alt_name("mace");
    set_alias("heavy mace");
    set_class(12);
    set_weight(3);
    set_value(600);
  }
  return 1;
}
