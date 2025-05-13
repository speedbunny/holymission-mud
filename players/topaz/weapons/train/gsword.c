inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("sword");
    short_desc="A sharp sword";
    long_desc="A well crafted, sharp sword.\n";
    set_alt_name("sword");
    set_alias("sharp sword");
    set_class(10);
    set_weight(3);
    set_value(500);
  }
  return 1;
}
