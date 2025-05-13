inherit "/obj/monster";
#include "/players/saffrin/defs.h"

object safflower;

void reset(int arg){

  ::reset(arg);
  if(!arg) {
     set_name("a horse");
     set_alias("horse");
     set_short("A horse");
     set_long("A proud brown horse with white speckles on its flanks.  Its soft brown eyes\n"+
                    "watch your every move.\n");
     set_level(7);
     set_size(4);
     set_aggressive(1);
     set_al(0);
     add_money(100 + random(100));

     MOVE(CLONE(HAM+"obj/sflower"),TO);
  }
}
