inherit "obj/monster";
    string chats;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("ghoul");
   set_level(3);
   set_al(-100);
   set_gender(1);
   set_race("undead");
   set_short("An evil ghoul");
   set_long("An evil corpse that has risen from the grave "+ 
            "to wreck havok on the living.\n");
   set_wc(0);
  set_walk_limit("/players/wilbie/graveyard");
  set_walk_chance(30);
   set_ac(2);
   set_size(3);

   set_aggressive(1);


   return;


}
