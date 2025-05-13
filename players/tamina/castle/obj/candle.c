#include "/players/tamina/defs.h"

inherit "obj/torch";

reset (arg) {
  ::reset (arg);
  if (arg) return;

  set_name("candle");
  set_short("Strange red Candle");
  set_long("This little red candle appears to be very magical.\n");
  set_smell("You smell a peculiar, aromatic scent from this candle.\n");
  set_fuel(3000);
  set_weight(2);
  set_greek_fire(1);

}

