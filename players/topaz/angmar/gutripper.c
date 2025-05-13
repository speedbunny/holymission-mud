inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    set_name("gutripper");
    set_short("Gutripper");
    set_long("You can only guess what devilish deeds this nasty tool was\n" +
             "used for.  It should serve well as a weapon though.\n");
    set_alt_name("weapon");
    set_alias("ripper");
    set_class(15);
    set_weight(2);
    set_value(1000);
  }
  return 1;
}
