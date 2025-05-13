#include "/players/tamina/defs.h"

inherit "obj/container";

reset(arg) {
  if(arg) return;

    set_name("scabbard");
    set_alias("sheath");
    set_short("A Scabbard");
    set_long(
"This is the magnificent Scabbard for the sword Excalibur of King Arthur\n"+
"The lock is made out of some black material.\n");
    set_value(1000);
    set_weight(3);
    set_max_weight(5);
    set_only_for("excalibur");
    set_can_close(0);
    set_opened(1);
}
