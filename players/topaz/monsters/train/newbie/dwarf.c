inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Small Dwarf");
    set_alt_name("small dwarf");
    set_alias("dwarf");
    set_race("dwarf");
    short_desc="A small dwarf";
    long_desc="This dwarf is small, even for a dwarf, but he\n" +
              "looks very formidable.\n";
    set_aggressive(0);
    set_level(10);
    set_ac(5);
    set_al(500);
    move_object(clone_object(WEAP + "train/dmace"),this_object());
    command("wield mace");
    move_object(clone_object(ARMR + "train/dshield"),this_object());
    command("wear shield");
  }
  return 1;
}
