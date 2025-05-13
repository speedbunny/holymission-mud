inherit "obj/armour";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("armour");
    short_desc="Armour";
    long_desc="Some Armour.\n";
    set_alias("some armour");
    set_type("armour");
    set_ac(1);
    set_weight(1);
    set_value(200);
  }
return 1;
}
