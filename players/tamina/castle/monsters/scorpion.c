inherit "obj/monster";

#include    "/players/tamina/defs.h"
#define AO  attacker_ob

void reset (int arg) 
{
  ::reset (arg);
  if (!arg) 
  {
     set_name("Giant Scorpion");
     set_alias("scorpion");
     set_short("A Giant Scorpion");
     set_long(
"This huge, well-armoured beast has a pair of sharp pincers at the\n"+
"front of its head, and a menacingly large stinger poised above its\n"+
"back.  It looks strangely intelligent...\n");
     set_level(41);
     set_gender(1);
     set_al(-500);
     set_aggressive(1);
     set_hp(3000);
     set_wc(46);
     set_ac(25);
     add_money(1000);
     set_dead_ob(TO);
  }
}

attack()
{ 
  int hit;

  if ((AO && ENV == E(AO)) && (!random(7)))
  {
    hit = 7 + random((45 - (AO->CON))/2);
 
    say("The Scorpion stabs at "+AO->NAME+" with its stinger !!\n");
    AO->add_poison(hit);
    AO->hit_player(hit - 5);
  }
  return ::attack();;
}

monster_died(ob)
{
  object tail;

  TRM (E(TO),
   "\nThe Giant Scorpion falls to the floor, and dies...\n"+
   "You see that the tail of the Scorpion looks still intact...\n\n");

  tail = CLO(COBJ + "tail");
  MO(tail, TO);
}
