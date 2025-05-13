inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("lag Monster");
    set_alias("monster");
    set_alt_name("lag");
    set_race("lagmonster");
    set_size(1);
    set_level(1);
    set_short("The infamous lag monster");
    set_long("This is the dreaded lag monster!\n");
    set_wc(1);
    set_ac(1);
    set_hp(1);
    set_al(-1000);
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}

monster_died(ob) {
    shout("Lag monster dances around the dead keyboard of Topaz.\n");
    tell_room(environment(this_object()),
        "Lag monster dances around the dead keyboard of Topaz!\n" +
        "Topaz died.\n");
    return 0;
}
