inherit "obj/armour";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("shield");
    short_desc="Small Shield";
    long_desc="A small, but good looking shield.\n";
    set_alias("small shield");
    set_type("shield");
    set_ac(1);
    set_weight(1);
    set_value(350);
  }
return 1;
}
