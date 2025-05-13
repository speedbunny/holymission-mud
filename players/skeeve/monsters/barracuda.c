#include "/players/skeeve/area.h"

inherit MONSTERS+"wmonster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("barracuda");
    set_alias("blue barracuda");
    set_short("A fast blue barracuda");
    set_long("The blue barracuda always searches for food.\n");
    set_race("fish");
   set_level(1);
   set_al(0);
   set_hp(1);
    set_sp(0);
    set_wc(13);
    set_ac(5);
    set_aggressive(1);
    set_wimpy(-1);
    set_dead_ob(this_object());
    set_call_time(30,60);  
  }
}
monster_died(ob) {
   this_player()->add_exp(-7);
     return 0;
}


