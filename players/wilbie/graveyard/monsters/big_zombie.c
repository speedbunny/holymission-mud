inherit "obj/monster";
    string chats;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("zombie");
   set_level(10+random(5));
   set_hp(4000);
   set_al(-100);
   set_gender(1);
   add_money(300+random(200));
   set_race("undead");
   set_short("An evil zombie");
   set_long("The largest Zombie you have ever seen in your life "+
   "and it's looking RIGHT AT YOU!!!\n");
   set_wc(10);
   set_ac(2);
   set_size(3);

   set_aggressive(1);


   return;


}
