#include "/players/tamina/defs.h"

inherit "obj/thing";

reset (arg) {
  ::reset (arg);
  if (!arg) {

    set_name("scroll");
    set_alias("parchment");
    set_short("A piece of Scroll");
    set_long(
"A small, torn part of a crumbling scroll.  It seems to be the middle\n"+
"part of a longer scroll.  But you might still be able to read it...\n");
    set_read_file("/players/tamina/castle/obj/scroll2.txt");
    set_value(20);

    }
}
