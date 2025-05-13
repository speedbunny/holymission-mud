inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Angel");
    set_short("A heavenly angel");
    set_long("A heavenly angel.\n" +
             "This angel is being held captive here by the demons.\n" +
             "You should probably try to free him.\n");
    set_alias("an angel");
    set_alt_name("angel");
    set_aggressive(0);
    set_level(30);
    set_wc(50);
    set_ac(10);
    set_al(1000);
    set_hp(3000);
  }
  return 1;
}
