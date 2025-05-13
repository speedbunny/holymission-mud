#include "/players/tamina/defs.h"
#define AO  attacker_ob

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("thing");
     set_short("A Thing");
     set_long(
"This strange monster looks like a menacing ball of spiky fur, \n"+
"with long, sharp teeth, that glint in the dim light around you.\n");
     set_level(35);
     set_race("unknown");
     set_al(-1000);
     set_aggressive(1);
     set_wc(33);
     set_ac(14);
     add_money(1);

    }

}

attack()
{ 
  int hit;

  if ((AO && ENV == E(AO)) && (random(101) > 15))
  {
    hit = 8 + random((38 - (AO->CON))/2);

    TOBJ(AO, "The Thing smothers you with its poisonous saliva !!\n"+
             "Poison is in your bloodstream !!!\n");
    AO->hit_player(5 + random(16));
    AO->add_poison(hit);   
  }
  return ::attack();
}
