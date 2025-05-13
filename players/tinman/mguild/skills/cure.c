

/* =============================================================== 
   Userdoc: Cure               /players/whisky/guild/skills/cure.c
   ---------------------------------------------------------------
   Art: healing hitpoints for spellpoints
   Damage || Heal: wisdom * 5 
   Cost: 70% spellpoints / healed hitpoints
   Special: learnable by training or master
   =============================================================== */

#define HEAL  ( _tpw * 5 ) 

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int cure(string arg)
{
   object mob;
   string name;
   string poss;
   int to_heal;
   int crit;


   if (arg && lower_case(arg)==_tpr && apply(call,_tp,"query_attack")) 
   {
      write("You are much too busy to cure yourself !\n");
      return 1;
   }
   else if (objectp(mob = chk_present(_tp,arg,HEAL*2/3)))
   {
      name = apply(call,mob,"query_name");
      poss = apply(call,mob,"query_possessive");

      if (!chk_skill(_tp,"monk_cure",5))
      {
          crit = random(100);
          write("Oops, critical failure !\n");
          if (mob != _tp)
              say(_tpn+" lays both hands on "+name+" !\n",mob,_tp);
             
          if (crit > 90)
          {
              apply(call,mob,"reduce_hit_point",(3+random(mob->query_hp())/3));
              tell_object(mob,"Autch !\n");
          }
          apply(call,_tp,"restore_spell_points", - ((1+ HEAL/4)) );
          return 1;
      }

      if (mob != _tp) 
      {
         write("You lay your hands on "+name+" and cure "+poss+" wounds !\n");
         say(_tpn+" lays both hands on "+name+" !\n",mob,_tp);
      }

      tell_object(mob,"You feel better !\n");
      to_heal = apply(call,mob,"query_max_hp") - apply(call,mob,"query_hp");

      if (to_heal > HEAL)
          to_heal = HEAL;
       apply(call,mob,"reduce_hit_point",-to_heal);
       apply(call,mob,"add_poison",-3);
      apply(call,_tp,"restore_spell_points",(-_cost(1 + to_heal*2/3)));
      return 1;
  }
  return 0;
}

