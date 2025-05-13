inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("kitten");
    set_alias("cat");
    set_alt_name("kitty");
    set_race("feline");
    set_size(1);
    set_level(1);
    set_short("A small kitten");
    set_long("This little kitten seems harmless.  And is!\n");
    set_wc(1);
    set_ac(1);
    set_hp(1);
    set_al(1000);
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}

monster_died(ob) {
    shout("Little Kitten munches on the dead body of Topaz!\n");
    tell_room(environment(this_object()),
        "Little Kitten munches on the dead body of Topaz!\n" +
        "Topaz died.\n");
    return 0;
}
