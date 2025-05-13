/* ===============================================================
   Art: healing hitpoints for spellpoints
   Damage || Heal: wisdom * 5
   Cost: 70% spellpoints / healed hitpoints
   =============================================================== */

#define HEAL  ( TP->query_wis() * 5 )
#include "/players/tinman/defs.h"

int main(string arg)
{
   object mob;
   string name;
   string poss;
   int to_heal;
   int crit;

  if(TP->query_ghost()) {
        write("Your ghostly body is not build for this attempt.\n");
      return 1;
    }
  if (arg && lower_case(arg)==TP->query_real_name() && TP->query_attack())
   {
      write("You are much too busy to cure yourself !\n");
      return 1;
   }
  if (!stringp(arg) || !(mob = present(arg,environment(TP)))) {
        write("Cure Whom?\n");
        return 1;
    }
  if(TP->query_sp() < HEAL*2/3) {
        write("You don't have enough power to perform that action!\n");
        return 1;
    }
  if (!living(mob)) {
        write(capitalize(arg)+" is not living!\n");
        return 1;
    }
      name = mob->query_name();
      poss = mob->query_possessive();

      if (mob != TP)
      {
         write("You lay your hands on "+name+" and cure "+poss+" wounds!\n");
         say(TP->query_name()+" lays both hands on "+name+" !\n",mob,TP);
      }
            tell_object(mob,"You feel better !\n");
        to_heal = (mob->query_max_hp() - mob->query_hp());
      if (to_heal > HEAL)
          to_heal = HEAL;
        mob->reduce_hit_point(-to_heal);
        mob->add_poison(-3);
        TP->restore_spell_points(-(1+to_heal*2/3));
	return 1;
  }
