inherit "obj/armour";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("gloves");
    short_desc="Gloves";
    long_desc="A well-made pair of gloves.\n" +
              "They look very dependable.\n";
    set_alias("gloves");
    set_type("glove");
    set_ac(1);
    set_weight(1);
    set_value(250);
  }
return 1;
}
