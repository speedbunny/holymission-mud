inherit "/obj/monster";
#include "/players/saffrin/defs.h"

object rose;

void reset(int arg){

  ::reset(arg);
  if(!arg) {
     set_name("a falcon");
     set_alias("falcon");
     set_short("A horse");
     set_long("A blue and white falcon with a dark orange beak.  Its long talons appear\n"+
                    "to be very sharp.\n");
     set_level(10);
     set_size(1);
     set_aggressive(1);
     set_al(0);
     add_money(100 + random(100));

     MOVE(CLONE(HAM+"obj/rose"),TO);
  }
}
