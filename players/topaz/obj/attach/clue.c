inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("clue");
    set_name("clue");
    set_short("A clue");
    set_long("This is a clue for Louie.\n");
    set_value(5000);
    set_weight(0);
}
