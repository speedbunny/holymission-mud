

/* restore */

#include "chk_pres.h"


int restore(string arg)
{
   object mob;
   string name;
   string poss;
   int to_heal;

   _chk_ghost();

   if (arg && lower_case(arg)==_tp->query_real_name() && _tp->query_attack())
   {
      write("You are much too busy to cure yourself !\n");
      return 1;
   }
   else if (objectp(mob = chk_present(arg, 100,30)))
   {
	int cost;	//##m##

      name = mob->query_name();
      poss = mob->query_possessive();
      if (mob != _tp) 
      {
         write(
         "You heal "+name+"'s wounds !\n");
         say(
         _tpn+" heals "+name+"'s wounds !\n",mob,_tp);
      }
      tell_object(mob,"You are full healed !\n");
      to_heal = mob->query_max_hp() - mob->query_hp();

/*
 * minimum cost is 100 SP otherwise a cleric can heal 2 HP per SP
 * and thus a limit is only give by his SP
 * ##m## 30.08.04
 */

	if(to_heal > _tp->query_sp()*2) to_heal = _tp->query_sp()*2;
	if(to_heal < 200) cost = 100;
	else cost = to_heal/2;

      mob->reduce_hit_point(-to_heal);
      _tp->restore_spell_points(-cost);
      return 1;
   }
  return 0;
}

      
       

      
       
            
            
        
       
       

