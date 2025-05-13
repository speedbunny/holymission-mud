inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (!arg) 
  {
    set_name("The Mystical Dragon");
    set_alt_name("mystic dragon");
    set_alias("silver dragon");
    set_race("dragon");
    set_gender(1);
    set_short("The Mystic Dragon");
    set_long(
  "You see a huge, imposing Dragon, covered completely in gleeming\n"+
  "Silver scales.  It has a pair of tiny wings folded on its back.\n"+
  "It's maw is full of row, upon row of sharp teeth.  Wisps of smoke\n"+
  "curl up from his nostrils.  You do not like the intelligent \n"+
  "expression on its face...\n");
    set_level(66);
    set_wc(40);
    set_ac(29);
    set_size(5);
    set_al(0);
    set_aggressive(1);
    set_dead_ob(TO);
    load_a_chat(16,
 ({"The Silver Dragon roars violently !!\n",
   "The Mystical Dragon spreads a mist about the room...\n",
   "The old Silver Dragon pounces on you !!\n",
   "The Dragon's breath makes you feel ill...\n" }) );

  }
}

int attack()
{
  object *victim;
  int i, j;

  if (::attack() && !random(9))
  {
    victim = all_inventory(E(TO));
         j = sizeof(victim);

    TRM (E (TO),
  "The Mystic Dragon breathes it deadly fumes into the room !!\n");

    for (i = 0; i < j; i++)
    {
      if (living(victim[i]) && victim[i]->RNAME!="merlin")
      {
        victim[i]->catch_tell("You are smothered by the fumes !!\n");
        victim[i]->add_poison(11);
        victim[i]->hit_player(40 + random(60));
        if (victim[i] && victim[i]->query_invis())
          victim[i]->set_vis();
      }
    }
    return 1;
  }
  return 0;
}

monster_died(ob)
{
  TRM(E (TO),
   "The Silver Dragon dissipates into mist...\n");
  destruct(TO);
}
