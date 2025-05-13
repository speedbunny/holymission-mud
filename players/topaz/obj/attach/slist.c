inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("shopping list");
    set_name("list");
    set_alt_name("shopping list");
    set_alias("the list");
    set_short("A shopping list");
    set_long("This is Figley's shopping list.\n" +
             "On it is written:\n" +
             "        bread\n" +
             "        butter\n" +
             "        yo-yo\n" +
             "        milk\n" +
             "        candy\n\n");
    set_value(10);
}
