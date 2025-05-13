inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("gladiator");
   set_level(5);
   set_wc(7);
   set_ac(1);
   set_al(-5);
   set_gender(1);
   set_race("human");
   set_short("Gladiator");
   set_long("This is one of the fighting men of the arena.  He is very strong\n"+
            "looking and he seems to be holding his own amongst the masses.\n");
   add_money(100);
   MO(CO("/players/bobo/obj/ghelmet"), TO);
   IC("wear helmet");
}
