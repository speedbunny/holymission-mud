inherit "obj/monster";
    object bone;
    object armor;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("ghast");
   set_level(5+random(5));
   set_ep(50);
   set_al(-100);
   set_gender(1);
   set_race("undead");
   set_short("An evil ghast");
   add_money(1000);
   set_long("An evil ghast with red glowing eyes\n");
   set_wc(0);
   set_ac(2);
   set_size(3);

   set_aggressive(1);
   armor = CO(ARM+"tatt_robes.c");
   MO(armor,this_object());
   init_command("wear plate");

   bone = CO(WEAP+"bone.c");
   MO(bone,this_object());
   init_command("wield bone");
   return;

   }

