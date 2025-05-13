inherit "/obj/monster";
#include "/players/saffrin/defs.h"

object safflower;

void reset(int arg){

  ::reset(arg);
  if(!arg) {
     set_name("a singing cardinal");
     set_alias("cardinal");
     set_short("A singing cardinal");
     set_long("A beautiful red cardinal singing a love tune to its mate.  Its sweet song taunts\n"+
                    "the light breeze for a response.\n");
     set_level(5);
     set_size(1);
     set_al(0);
     add_money(100 + random(100));

     MOVE(CLONE(HAM+"obj/sflower"),TO);
  }
}
