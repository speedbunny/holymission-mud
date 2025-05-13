inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("topaz doll");
    set_name("doll");
    set_alt_name("little topaz");
    set_alias("topaz doll");
    set_short("A Topaz Doll");
    set_long("A little doll that looks like Topaz.  :)\n");
    set_value(0);
    set_weight(0);
}
