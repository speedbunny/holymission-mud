inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("gladiator");
   set_level(6);
   set_wc(8);
   set_ac(2);
   set_al(-5);
   set_gender(1);
   set_race("human");
   set_short("Gladiator");
   set_long("This gladiator seems battle worn and hardened by continuous\n"+
            "combat.  He has rippling muscles and his tunic bears ribbons\n"+
            "of victory in combat.\n");
   add_money(100);
   MO(CO("/players/bobo/obj/gsword"), TO);
   MO(CO("/players/bobo/obj/gshield"), TO);
   IC("wear shield");
}
