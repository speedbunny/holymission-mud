inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("gladiator");
   set_level(7);
   set_wc(9);
   set_ac(3);
   set_al(-20);
   set_gender(1);
   set_race("human");
   set_short("Gladiator");
   set_long("This is the nightiest gladiator of them all.  He is the most\n"+
            "well prepared for battle and has thick powerful arms.\n");
   add_money(150);
   MO(CO("/players/bobo/obj/gsword"), TO);
   MO(CO("/players/bobo/obj/gshield"), TO);
   MO(CO("/players/bobo/obj/ghelmet"), TO);
   IC("wear shield");
   IC("wear helmet");
}
