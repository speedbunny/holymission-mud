inherit "/obj/monster";

reset(arg){
 ::reset(arg);
 if(arg) return 1;
   set_name("raccoon");
   set_race("raccoon");
   set_short("A raccoon");
   set_long("A little fuzzy raccoon.\n");
   set_level(1);
//   set_hp(50);
   set_ac(1);
   set_wc(5);
   add_money(50);
   set_dead_ob(this_object());

	return 1; 
}
#include "/players/airborne/new/monsters/dead.h"
