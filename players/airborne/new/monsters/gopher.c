inherit "/obj/monster";

reset(arg){
 ::reset(arg);
 if(arg) return 1;
   set_name("gopher");
   set_race("gopher");
   set_short("A gopher");
   set_long("A little fuzzy gopher.\n");
   set_level(1);
//   set_hp(50);
   set_ac(1);
   set_wc(5);
   add_money(50);
   set_dead_ob(this_object());

	return 1; 
}
#include "/players/airborne/new/monsters/dead.h"
