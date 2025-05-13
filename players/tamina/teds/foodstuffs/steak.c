inherit "/players/tamina/teds/inherits/food";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  set_name("steak");
  set_short("A large, juicy steak");
  set_long("A nice 1/2-pounder, which looks very tasty.\n");
  set_heal(10 + random(15));
  set_mess("You chew for a while on the steak.\n");
  set_weight(1);
  set_value(20);
}

