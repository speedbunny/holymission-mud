inherit "obj/armour";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    set_name("ring");
    set_id("dkring");
    set_short("The Demon King's Ring");
    set_long("This ring belongs to the Demon King, Eriskull.\n" +
             "This ring gives authorization to the demon treasurer to\n" +
             "dispense monies from the treasury vault.\n");
    set_alias("ring");
    set_type("ring");
    set_ac(1);
    set_weight(2);
    set_value(500);
  }
return 1;
}
