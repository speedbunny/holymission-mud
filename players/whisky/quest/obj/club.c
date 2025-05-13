#include "../monkway.h"
inherit "obj/weapon";
  int i;
  reset(arg) {
   ::reset(arg);
   if (arg) return; 
     set_name("club");
     set_alias("stone club");
     set_short("A heavy stone club");
     set_long("The weapon of a stone golem.\n"+
              "It's seems to be very strong.\n");
     set_weight(15);
     set_type(1);
     set_class(18);
     set_value(200);
     i=0;
     set_hit_func(TO);
   }
   weapon_hit(ob) {
    if ((random(10) < 3) && (i<500)){
     tell_room(environment(TP),"Stones smash out from "+TPN+"'s club and hurt "+
     ob->query_name()+" badly.\n");
     i++;
    return (random(10));
    }
    else if ((random(10)< 3) && (i>=500)) {
     tell_room(environment(TP),"Stones smash out from "+TPN+"'s club against "+
     ob->query_name()+".\nBut suddenly "+TPN+"'s club breaks into peaces.\n"); 
     return (random(25));
     destruct(TO);
   }
   return;
  }
     
     
