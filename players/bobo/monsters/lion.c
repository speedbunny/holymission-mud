inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("lion");
   set_level(4);
   set_wc(7);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("lion");
   set_short("Lion");
   set_long("This is a majestic looking lion.  It stands roughly four feet\n"+
            "tall, has a thick mane and a loud roar that shows his large "+
            "teeth.\n");
   MO(CO("/players/bobo/obj/lionhide"),TO);
   IC("powerup");
}
