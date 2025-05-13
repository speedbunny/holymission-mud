inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("record books");
    set_name("books");
    set_alt_name("records");
    set_alias("record books");
    set_short("Record Books");
    set_long("The Demon King's record books.\n" +
             "You can't seem to read any entries though.\n");
    set_value(200);
    set_weight(1);
}
