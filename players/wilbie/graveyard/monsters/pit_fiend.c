inherit "obj/monster";
    object sword;
    object armor;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("pit fiend");
   set_alias("pit");
   set_alt_name("fiend");
   set_level(50+random(5));
   set_al(-999);
   set_gender(1);
   add_money(10000);
  set_hp(30000);
   set_race("demon");
   set_short("A horrible pit fiend!");
   set_long("This minion of hell serves the powers of darkness with great "+
            "pleasure.  He looks at you and bellows an evil curse, then "
            "licks his lips in hunger.  Crimson flames encircle leap from "+
            "his blood hued flesh.\n");
   set_wc(7);

  set_ac(2);
   set_size(5);
   set_aggressive(1);
   set_spell_mess1("The pit fiend cackles as his flames burst outward!");
   set_chance(35);
   set_spell_mess2("You step too close to the pit fiends unholy flames!!\n"+
   "You are burned badly!!  That REALLY Hurt!!!");
   set_spell_dam(50+random(25));

   armor = CO(ARM+"fiend_armor.c");
   MO(armor,this_object());
   init_command("wear plate");

   sword = CO(WEAP+"fiend_sword.c");
   MO(sword,this_object());
   init_command("wield sword");
   return;
}
