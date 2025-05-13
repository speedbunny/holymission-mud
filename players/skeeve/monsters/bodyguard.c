inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("guard");
    set_alias("bodyguard");
    set_short("The managers bodyguard");
    set_long("He is a large, strong and experienced fighter\n"
        +"and he takes his job very seriously.\n");
    set_race("dwarf");
    set_size(4);
    set_al(200);
    set_level(50);
    set_hp(6000);
    set_sp(0);
    set_wc(1);
    set_ac(2);
    set_aggressive(0);
    set_no_steal();
    add_money(5 + random (11));
    set_whimpy(-1);
  }
  WEAPON("guard_sword",this_object());
  ARMOUR("white trousers","white_trousers",this_object());
  ARMOUR("white halfboots","white_halfboots",this_object());
  ARMOUR("white wristlets","white_wristlets",this_object());
  ARMOUR("white platemail","white_platemail",this_object());
  ARMOUR("white helmet","white_helmet",this_object());
  ARMOUR("white gauntlets","white_gauntlets",this_object());
  ARMOUR("white cloak","white_cloak",this_object());
  ARMOUR("white shield","white_shield",this_object());
}
