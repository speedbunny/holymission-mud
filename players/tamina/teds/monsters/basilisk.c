inherit "obj/monster";

#include "/players/tamina/defs.h"
#define AO  attacker_ob

void reset(int arg) 
{
  ::reset(arg);
  if(!arg) 
  {
    set_name("basilisk");
    set_race("basilisk");
    set_short("Thicket Basilisk");
    set_long(
"This is a small relation of a black Dragon.\n"+
"It's gaze is known to be deadly...\n");
    set_size(2);
    set_level(28);
    set_race("dragon");
    set_al(-500);
    set_aggressive(1);
    set_wc(25);
    set_ac(12);
  }
}

attack()
{ 
  int hit;

  if ((AO && ENV == E(AO)) && (random(101) > 15))
  {
    hit = 8 + random((38 - (AO->CON))/2);

    TOBJ(AO, "The Basilisk's glare inflicts grave damage on you !!\n");

    AO->hit_player(hit/2, 5, ({ 5, 8 }) );
    AO->add_poison(hit);   
  }
  return ::attack();
}
