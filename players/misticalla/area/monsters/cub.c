inherit "obj/monster";

#include "/players/misticalla/defs.h"
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("bear cub");
    set_alias("cub");
    set_short("A cute little cub");
    set_long("It is a cute little cub looking for food and its mommy.\n");
    set_level(5);
    set_size(2);
    set_al(100);
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}
   monster_died(ob) {
  move_object(clone_object(MMONSTERS+"mbear"),
             environment(this_object()));
 say("Suddenly mother bear arrives. She looks angry.\n");
  return 0;
}

