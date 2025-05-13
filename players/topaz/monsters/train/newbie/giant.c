inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Baby giant");
    set_alt_name("baby giant");
    set_alias("baby");
    set_race("giant");
    short_desc="A big baby giant";
    long_desc="A mean looking baby giant that doesn't seem\n" +
              "to have much affection for anyone or anything.\n";
    set_aggressive(1);
    set_level(7);
    set_ac(4);
    set_al(-200);
    move_object(clone_object(WEAP + "train/gsword"),this_object());
    command("wield sword");
    move_object(clone_object(ARMR + "train/ggloves"),this_object());
    command("wear gloves");
  }
  return 1;
}
