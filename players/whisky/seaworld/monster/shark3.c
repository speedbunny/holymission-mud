
/* shark3 */

inherit "/obj/monster";
#include "bad_fish.h"

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;
    set_name("shark");
    set_alias("medium size shark");
    set_race("fish");
    set_aggressive(1);
    set_short("A medium size Shark");
    set_long("A small, white shark.\n");
    set_level(20);
    set_aggressive(1);
    set_has_gills();
    set_size(5);
    set_spell_mess1("H A C K   H A C K");
    set_spell_mess2("H A C K   H A C K");
    set_chance(2);
    set_spell_dam(20+random(80));
    move_object(clone_object("players/whisky/seaworld/obj/teeth"),this_object());
    move_object(clone_object("/players/whisky/obj/heal_potion"),this_object());
    init_command("wield teeth");
}

run_away() { return 0; }
stop_fight() { return 0; }
