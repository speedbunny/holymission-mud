inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("pinball machine");
    short_desc="A Pinball Machine";
    long_desc="This is a magically powered pinball machine.\n" +
             "To play it just type, 'play pinball'.\n" +
             "You can gain experience playing it, but it costs 5 coins\n" +
             "to play.\n";
    set_alt_name("machine");
    set_alias("pinball");
    set_weight(500);
    set_value(200);
  }
  return 1;
}
