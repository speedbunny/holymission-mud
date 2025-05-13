#include "/players/tamina/defs.h"

inherit "obj/thing";

reset (arg) {
  ::reset (arg);
  if (!arg) {

    set_name("instructions");
    set_alias("set");
    set_short("A Set of instructions");
    set_long(
"This seems to be a piece of parchment with a lot of messy handwriting\n"+
"on it.  But you might be able to make out some of the words...\n");
    set_read_file(COBJ + "inst.txt");
    set_value(75);

    }
}
