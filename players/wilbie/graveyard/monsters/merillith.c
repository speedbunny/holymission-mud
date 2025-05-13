inherit "obj/monster";
    object sword;
    object axe;
    object spear;
    object dagger;
    object blade;
    object shard;
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("merillith");
   set_number_of_arms(6);
  set_level(20);
   set_ep(10000);
   set_al(-100);
   set_gender(2);
   add_money(1000);
   set_race("demon");
   set_short("A six armed demon");
  set_long("A six armed demon of great evil...\n");
   set_wc(2);
   set_ac(1);
   set_size(3);
   set_aggressive(1);


   sword = CO(WEAP+"msword.c");
   MO(sword,this_object());
   init_command("wield sword");

   axe = CO(WEAP+"maxe.c");
   MO(axe,this_object());
   init_command("wield axe");

   spear = CO(WEAP+"mspear.c");
   MO(spear,this_object());
   init_command("wield spear");

    dagger = CO(WEAP+"mdagger.c");
   MO(dagger,this_object());
    init_command("wield dagger");

   shard = CO(WEAP+"mshard.c");
   MO(shard,this_object());
   init_command("wield shard");

   blade = CO(WEAP+"mblade.c");
   MO(blade,this_object());
   init_command("wield blade");
   return;
}

