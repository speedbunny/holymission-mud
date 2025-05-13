inherit "obj/monster";
    object mace;
    object armor;
#include "/players/wilbie/def.h"
object mace;
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("fanatical priestess");
   set_walk_limit("/players/wilbie/graveyard");
//   set_walk_chance(24);
   set_alias("priestess");
   set_alt_name("fanatical");
   set_level(15);
   set_hp(500);
   set_al(-100);
   set_gender(2);
   add_money(456);
   set_race("human");
   set_short("A fanatical priestess");
   set_long("This fanatical, insane looking young woman is looking "+
            "to serve her evil goddess by any means she can.\n");
   set_wc(5);
   set_ac(2);
   set_size(3);
   set_aggressive(1);
   set_spell_mess1("The priestess casts an arcane spell!!");
   set_spell_mess2("You feel your life force weakening!");
   set_chance(35);
   set_spell_dam(25);

   return;
}
