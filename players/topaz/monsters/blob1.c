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
    set_level(4);
    set_wc(8);
    set_ac(3);
    set_al(-250);
    set_hp(250);
    set_dead_ob(this_object());
  }
  return 1;
}

monster_died(ob) {
    write("The blob breaks up into three smaller pieces!\n");
    say("The blob breaks up into three smaller pieces!\n");
    move_object(clone_object(MNST + "blob2"),environment(this_object()));
    move_object(clone_object(MNST + "blob2"),environment(this_object()));
    move_object(clone_object(MNST + "blob2"),environment(this_object()));
    return 0;
}
