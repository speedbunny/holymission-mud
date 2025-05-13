inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("tiger");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("tiger");
   set_short("Tiger");
   set_long("The tiger is a regal animal that has stripes running down its\n"+
            "back.  It has sharp looking teeth and claws.\n");
   MO(CO("/players/bobo/obj/tigerclaw"),TO);
}
