inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("club");
    short_desc="A small club";
    long_desc="A small, yet mean looking club.\n";
    set_alt_name("club");
    set_alias("small club");
    set_class(8);
    set_weight(2);
    set_value(300);
  }
  return 1;
}
