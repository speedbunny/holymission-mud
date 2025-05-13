#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

inherit MONSTERS+"wmonster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("fisher");
    set_alias("fisherman");
    set_short("A fisher");
    set_long("It's a fisher. He works for the druid Lakmir.\n");
    set_race("human");
    set_level(20);
    set_hp(1200);
    set_sp(0);
    set_al(200);
    set_wc(15);
    set_ac(10);
    set_aggressive(0);
    set_no_steal();
    set_wimpy(-1);
    set_male();
    set_size(3);
    set_call_time(80,40);
  }
  WEAPON("harpoon",this_object());
}

query_stay_ocean(){return 1;}
