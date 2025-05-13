

/* =============================================================== 
   Userdoc: Pentagram     /players/whisky/guild/skills/pentagram.c
   ---------------------------------------------------------------
   Art: Strange guild Symbol, made of fosforized earth
   Damage || Heal: none
   Cost: none
   Special: no real skill, a symbol which shows you are a friend 
            of this guild and can be used as light source. 
   =============================================================== */

#define COST _cost( (100 - _tpw > 40 ? 100 - _tpw : 40) )

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
}

int pentagram()
{
    if (chk_ghost(_tp))
        return 1;
    else if (_tpl < 8)
    {
      write("You have to be closer to your god !\n");
       return 1;
     }
    else if (_tps < COST)
    {
       write("You are not powerful enough to build a pentagram !\n");
       return 1;
    }
    else
    {
       write("You concentrate and build a pentagram !\n");
       say(_tpn+" builds up a pentagram !\n",_tp);
       move_object(clone_object(_obj+"pentagram"),_tp);
       apply(call,_tp,"restore_spell_points",-COST);
       return 1;
    }
  return 1;
}
