#include "/players/tamina/defs.h"

inherit "obj/thing";

reset(arg) {
  ::reset(arg);
  if (arg) return;

    set_name("fuse");
    set_short("A Fuse");
    set_long("A small piece of blue paper, that you think is specifically\n"+
             "intended to light only one thing...\n");
    set_weight(1);
    set_value(60);
    set_can_get(1);
}
