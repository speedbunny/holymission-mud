inherit "/obj/monster";

reset(arg){
 ::reset(arg);
 if(arg) return 1;
   set_name("fox");
   set_race("fox");
   set_short("A fox");
   set_long("A little fuzzy fox.\n");
   set_level(1);
   set_hp(50);
   set_ac(1);
   set_wc(5);
   add_money(50);
   set_dead_ob(this_object());

	return 1; 
}
#include "/players/airborne/new/monsters/dead.h"
