#include    "/players/tamina/defs.h"
#define AO  attacker_ob

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("hunter");
     set_short("A Hunter");
     set_long(
"A vicious looking hound, with unusually large fangs, that seem to\n"+
"drip with steaming saliva.\n");
     set_level(33);
     set_gender(1);
     set_al(-500);
     set_aggressive(1);
     set_wc(30);
     set_ac(15);
     add_money(50);

    }

}

attack()
{ 
  int hit;

  if ((AO && ENV == E(AO)) && (random(101) > 15))
  {
    hit = 4 + random ((38 - (AO->CON))/2);

    TOBJ(AO, "The Hunter's fangs plunge deep into your flesh.\n"+
             "It injects its poison into your bloodstream !!!\n");
    AO->add_poison(hit);
  }
  return ::attack();
}

