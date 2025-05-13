inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("weapon");
    short_desc="Weapon";
    long_desc="A weapon.\n";
    set_alt_name("a weapon");
    set_alias("A Weapon");
    set_class(1);
    set_weight(1);
    set_value(200);
  }
  return 1;
}
