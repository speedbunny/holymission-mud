inherit "obj/monster";

#include "/players/topaz/defs.h"

object mamabear;
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("bear Cub");
    set_alias("bear");
    set_alt_name("cub");
    set_race("ursa");
    set_size(1);
    set_level(5);
    set_short("A cute bear cub");
    set_long("This is a cute little bear cub.\n" +
             "It isn't hurting anyone.  It's just playing\n" +
             "by itself.\n");
    set_wc(7);
    set_ac(3);
    set_hp(110);
    set_al(200);
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}

monster_died(ob) {
    tell_room(environment(this_object()),
        "As you kill the bear cub, a mother bear comes crashing through\n" +
        "the bushes!  She doesn't seem happy about what you've done!\n");
        move_object(mamabear=clone_object(MNST + "attach/bearmom"),environment(TO));
        mamabear->attacked_by(TP);
    return 0;
}
