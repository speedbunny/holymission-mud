inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("razor");
    set_alt_name("razor blade");
    set_alias("blade");
    set_short("Beardy's Razor Blade");
    set_long("This razor blade was made especially for Beardy by Topaz.\n");
    set_value(300);
    set_weight(0);
}

drop() {
  write("As you drop the razor, ir disintegrates.\n");
  destruct(this_object());
  return 1;
}
