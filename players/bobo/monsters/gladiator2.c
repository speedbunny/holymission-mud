inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("gladiator");
   set_level(5);
   set_wc(7);
   set_ac(4);
   set_al(-5);
   set_gender(1);
   set_race("human");
   set_short("Gladiator");
   set_long("The gladiator standing before you is powerfully built and well\n"+
         "protected.  He uses his shield expertly to guard himself.\n");
   add_money(100);
   MO(CO("/players/bobo/obj/gshield"), TO);
   IC("wear shield");
}
