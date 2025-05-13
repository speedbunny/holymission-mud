inherit "obj/monster";
    object sword;
#include "/players/unuscione/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("kobold");
   set_level(3);
   set_hp(75);
   set_ep(50);
   set_al(50);
   set_gender(1);
   add_money(50);
   set_race("kobold");
   set_short("An ugly little kobold");
   set_long("An ugly dog like person about 3' tall\n");
   set_wc(0);
   set_ac(2);
   set_size(2);
   set_aggressive(1);
   set_spell_mess2("The Kobold bites your leg");
   set_chance(20);
   set_spell_dam(5);
   sword=CO("/players/unuscione/weapons/ksword");
  MO(sword,TO);
   init_command("wield sword");
   return;
}
