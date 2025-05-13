inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("caesar");
   set_level(10);
   set_wc(12);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Caesar");
   set_long("This is the mighty Caesar.  His imperial robe displays his\n"+
            "greatness in it's opulence.  It is thick and flowing.  He is\n"+
            "still watching the fighting despite the scene around him.\n");
   add_money(300);
   MO(CO("/players/bobo/obj/gdagger"), TO);
}
