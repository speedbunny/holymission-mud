inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("gladiator");
   set_level(5);
   set_wc(8);
   set_ac(1);
   set_al(-5);
   set_gender(1);
   set_race("human");
   set_short("Gladiator");
   set_long("This mighty gladiator looks as though he has been hardened by\n"+
            "battle.  His tunic is stained with blood and his sword arm is\n"+
            "very strong.\n");
   add_money(100);
   MO(CO("/players/bobo/obj/gsword"), TO);
}
