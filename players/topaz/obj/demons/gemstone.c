inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("queen's gem");
    set_name("gem");
    set_alt_name("small gem");
    set_short("A small gem");
    set_long("A beautiful small gem.\n");
    set_value(500);
    set_weight(1);
}
