inherit "obj/armour";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("the White Crown");
  set_short("The White Crown");
  set_long("This is the infamous White Crown!\n" +
           "It is rumoured to grant its wearer extra strength if\n" +
           "it is pleased by its wearer's actions!\n" +
           "Maybe you could try it on?\n");
  set_alias("crown");
  set_type("helmet");
  set_ac(1);
  set_weight(2);
  set_value(10000);
}
