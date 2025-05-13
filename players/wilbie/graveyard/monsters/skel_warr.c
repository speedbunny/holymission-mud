inherit "obj/monster";
    object sword;
    object armor;
    string chats;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("skeleton");
   set_level(5+random(5));
   set_move_at_reset();
   set_hp(203);
   set_al(-100);
   set_gender(1);
   add_money(200);
   set_race("undead");
   set_short("An evil skeletal warrior");
   set_long("An animated skeletal warrior.  It seems to be trying "+
            "to guard this place against intruders.\n");
   set_wc(0);
   set_ac(2);
   set_size(3);

   set_aggressive(1);
   set_spell_mess1("The skeleton emanates a cold chill!");
   set_spell_mess2("The skeleton chills you with a touch!!");
   set_chance(20);
   set_spell_dam(10);


   return;

    if(!chats) {
   chats=allocate(3);
   chats[0]="The bones of the skeleton creak and rattle...";
   chats[1]="The skeleton glares at you.";
   chats[2]="The skeleton cackles!!";
   }
   load_chat(50,chats);

}
