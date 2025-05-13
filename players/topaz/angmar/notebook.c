inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("notebook");
    set_name("notebook");
    set_alt_name("book");
    set_short("A notebook");
    set_long("A small notebook.\n" +
             "You can't read anything in it though.\n" +
             "It is filled with just some scribbles.\n");
    set_value(10);
    set_weight(1);
}
