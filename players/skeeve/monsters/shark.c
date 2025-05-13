#include "/players/skeeve/area.h"

inherit MONSTERS+"wmonster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("shark");
    set_alias("white shark");
    set_alt_name("dangerous shark");
    set_short("A dangerous white shark");
    set_long("The white shark is always hungry. He loves to eat flesh!\n");
    set_race("fish");
   set_level(1);
    set_str(25);
   set_al(0);
    set_hp(1);
    set_sp(0);
    set_wc(16);
    set_ac(7);
    set_aggressive(1);
    set_wimpy(-1);
    set_size(4);
    set_dead_ob(this_object());
    set_gender(1+random(2));
    set_call_time(80,40);
  }
}
monster_died(ob)
{
this_player()->add_exp(-10);
  return 0;
}

