inherit "obj/monster";
    string chats;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("zombie");
//  set_walk_chance(10);
set_walk_limit("/players/wilbie/graveyard");
   set_level(10+random(5));
   set_hp(400);
   set_al(-100);
   set_gender(1);
   add_money(300+random(200));
   set_race("undead");
   set_short("An evil zombie");
   set_long("A powerful undead corpse that has risen from the grave "+
            "to serve some evil purpose.\n");
   set_wc(0);
   set_ac(2);
   set_size(3);

   set_aggressive(1);


   return;


}
