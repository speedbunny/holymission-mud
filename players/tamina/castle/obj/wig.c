#include "/players/tamina/defs.h"

inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("wig");
    set_type("helmet");
    set_short("A Curly Blue Wig");
    set_long(
     "This is a blue wig, worn by a strange man, but by the feel of it,\n"+
     "you sense there are some protective powers associated with this.\n");
    set_ac(1);
    set_value(790);
    set_weight(2);
    set_size(0);

    }

}

query_mage_wear()  { return 1; }
query_monk_wear()  { return 1; }
query_ninja_wear() { return 1; }

