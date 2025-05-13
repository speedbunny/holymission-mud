#include "/players/tamina/defs.h"

inherit "obj/thing";

reset(arg) {
  ::reset(arg);
  if (arg) return;

    set_name("funnel");
    set_short("A Funnel");
    set_long("This is a small funnel, that you guess could be used to \n"+
             "pour something through.\n");
    set_weight(1);
    set_value(50);
    set_can_get(1);
}


