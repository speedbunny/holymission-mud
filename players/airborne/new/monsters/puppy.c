inherit "/obj/monster";

reset(arg){
 ::reset(arg);
 if(arg) return 1;
   set_name("puppy");
   set_race("dog");
   set_short("A puppy");
   set_long("A little fuzzy puppy.\n");
   set_level(1);
   set_hp(50);
   set_ac(1);
   set_wc(5);
   add_money(50);
   set_dead_ob(this_object());

	return 1; 
}
#include "/players/airborne/new/monsters/dead.h"
