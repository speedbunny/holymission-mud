inherit "obj/monster";
    object sword;
    object armor;
#include "/players/wilbie/def.h"
object sword;
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("skeletal knight");
   set_alias("knight");
   set_level(15);
   set_hp(500);
   set_al(-100);
   set_gender(1);
   add_money(456);
   set_race("undead");
   set_short("An evil skeletal warrior");
   set_long("An animated skeletal knight of some unholy cause.  It "+
            "glares at you with hatred in its read glowing eyes.\n");
   set_wc(5);
   set_ac(2);
   set_size(3);
   set_aggressive(1);
   set_spell_mess1("Skeletal knight chills the air around him...");
   set_spell_mess2("Skeletal knight cackles as he chills your soul!!");
   set_chance(35);
   set_spell_dam(25);


   return;
}
