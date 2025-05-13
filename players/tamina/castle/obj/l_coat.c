/*  This is a special Lab Coat  */

#include "/players/tamina/defs.h"

inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("lab coat");
    set_alias("coat");
    set_type("cloak");
    set_short("A White Lab Coat");
    set_long(
"This is a white Lab Coat.  But you sense that it is no ordinary coat.\n"+
"Perhaps it has some magical properties...?\n");
    set_value(1000);
    set_ac(1);
    set_weight(3);

}
query_mage_wear()  {  return 1;  }
query_monk_wear()  {  return 1;  }
query_ninja_wear()  {  return 1;  }

