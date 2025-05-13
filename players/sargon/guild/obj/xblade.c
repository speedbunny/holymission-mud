#include "/players/sargon/define.h"
inherit "obj/weapon";

reset(arg) {
if (arg) return;

   set_name("cirular blade");
   set_id("Circular-Blade");
   set_short("Xena's Circular Blade");
   set_alt_name("blade");
   set_long("A circular blade used by the famous she-wench Xena. It's\n"+
           " rumored that Helios had forged this weapon in the great\n"+
	   "heat at the center of the sun. It feels as magical as it looks.\n");
   set_value(8000);
   set_weight(6);
   set_type(1);
   set_hit_func(TO);
}

weapon_hit(attacker) {
 write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"+
       "The blade flies out of your hand then see blood gurgle out of\n"+
       ""+attacker->N+"'s mouth as his throat is ripped to shreads!\n"+
       "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
   say("The circular blade flies across the room and you hear screaming as\n"+ 
       "it cuts "+attacker->query_name()+"'s neck!!\n");
   return 15+random(10);
}
