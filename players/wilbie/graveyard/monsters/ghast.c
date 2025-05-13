inherit "obj/monster";
    object bone;
    object armor;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("ghast");
   set_level(5+random(5));
   set_walk_limit("/players/wilbie/graveyard");
//   set_walk_chance(30);
   set_hp(203);
   set_al(-100);
   set_gender(1);
   add_money(200);
   set_race("undead");
   set_short("An evil ghast");
   set_long("An evil, undead corpse with red glowing eyes.  "+
            "It seeks to destroy all living things.\n");
   set_wc(0);
   set_ac(2);
   set_size(3);

   set_aggressive(1);
   return;

   }

