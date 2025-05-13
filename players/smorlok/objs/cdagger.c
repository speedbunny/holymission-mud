inherit "/obj/weapon";
#include "/players/smorlok/ansi.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dagger");
    set_alt_name("sharp dagger");
    set_class(7);
    set_weight(1);
    set_short("A sharp, colored embellished dagger");
    set_long("This is a "+RED+"c"+HIR+"o"+HIY+"l"+HIG+"o"+HIB+"r"+HIM+"e"+NOR+""+MAG+"d"+NOR+" test dagger.\n");
    set_value(100);
  } 
}
