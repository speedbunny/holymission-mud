inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Baby troll");
    set_alt_name("baby troll");
    set_alias("baby");
    set_race("troll");
    short_desc="An ugly baby troll";
    long_desc="An ugly baby troll, with a sneer on its\n" +
              "ugly little face.\n";
    set_aggressive(1);
    set_level(4);
    set_ac(3);
    set_al(-200);
    move_object(clone_object(WEAP + "train/btclub"),this_object());
    command("wield club");
  }
  return 1;
}
