inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Blob");
    set_alias("blob");
    set_alt_name("the blob");
    set_race("monster");
    short_desc="A lumpy blob";
    long_desc="An ugly, lumpy blob.\n" +
              "It looks really pathetic.\n";
    set_aggressive(1);
    set_level(3);
    set_wc(7);
    set_ac(2);
    set_al(-200);
    set_hp(225);
    set_dead_ob(this_object());
  }
  return 1;
}

monster_died(ob) {
    write("The blob breaks up into three smaller pieces!\n");
    say("The blob breaks up into three smaller pieces!\n");
    move_object(clone_object(MNST + "blob3"),environment(this_object()));
    move_object(clone_object(MNST + "blob3"),environment(this_object()));
    move_object(clone_object(MNST + "blob3"),environment(this_object()));
    return 0;
}
