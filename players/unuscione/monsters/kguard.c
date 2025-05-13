inherit "obj/monster";
   object sword, vest;
#include "/players/unuscione/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("A ugly kobold guard");
   set_alt_name("kobold");
   set_alias("guard");
   set_level(5);
   set_hp(125);
   set_ep(150);
   set_gender(1);
   add_money(150);
   set_race("kobold");
   set_short("An ugly kobold guard");
   set_long("A kobold guard, gnawling on kender bones.\n");
   set_wc(2);
   set_ac(2);
   set_size(2);
  set_aggressive(1);
   sword=CO("/players/unuscione/weapons/ksword");
   vest=CO("/players/unuscione/armour/kvest");
  MO(vest, TO);
  MO(sword,TO);
   init_command("wield sword");
   command("wear vest");
   return;
}
