inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Spider");
    set_alias("spider");
    set_race("arachnid");
    set_size(2);
    set_level(5);
    set_short("Large Spider");
    set_long("This spider is a rather large, but non poisonous variety.\n" +
             "Its web stretches between two widely spaced trees to allow\n" +
             "it to catch insects as well as small birds.\n");
    set_wc(7);
    set_ac(3);
    set_hp(50+random(20));
    set_al(0);
    set_dex(8);
    set_aggressive(0);
    add_money(10);
  }
}

