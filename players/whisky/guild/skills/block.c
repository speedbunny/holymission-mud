

/* =============================================================== 
   Userdoc: Block          /players/whisky/guild/skills/block.c
   ---------------------------------------------------------------
   Art: Guardian, trying to hinder the victims attemt to run away
   Damage || Heal: none
   Cost: none
   Special: learnable by training or master / dexcombat any round
            of blocking / anyhow players ever can escape. 
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int block(string arg)
{
   object mob, shad;
   mixed skill;
   
    if (objectp(mob = chk_present(_tp,arg,0)))
    {
       write("Ok, you try to hinder "+arg+"'s attemt to run away !\n"); 
       say(_tpn+" carefully checks all possible exits !\n");

       if (!chk_skill(_tp,"monk_block",5))
           return 1;

       if (apply(call,mob,"block_shad") && 
           apply(call,mob,"query_blocker")==_tpr )
                destruct(apply(call,mob,"block_object"));

       if ( _tpd > random(apply(call,mob,"query_dex")) ) 
       {
           shad = clone_object("/players/whisky/guild/shadows/block_shad");
           apply(call,shad,"set_blocker",_tpr);
           apply(call,shad,"start_shadow",mob,200*_lg,"block_shad");
           apply(call,mob,"set_trapped",1);
       }
       return 1;
   }
   return 0;
}
            
