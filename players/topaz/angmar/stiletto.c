inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    set_name("stiletto");
    set_short("A stiletto");
    set_long("Ouch! Looks nasty!\n");
    set_class(13);
    set_weight(1);
    set_value(700);
  }
  return 1;
}
