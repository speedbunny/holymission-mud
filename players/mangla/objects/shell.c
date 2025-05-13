#include "/spells/spell.h"
inherit "obj/armour";

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("Shell armour");
    set_size(2);
     set_type("shield");
     set_ac(4);
     set_short("A hard shell");
     set_long("A hard piece of shells that might fit over your chest.\n");
    set_value(4);
     set_weight(1);
     set_alias("shell");
     modify_stat(
                 1,
                 5
                  );
  }
}

