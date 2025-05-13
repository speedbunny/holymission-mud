


/* =============================================================== 
   Userdoc: Protect         /players/whisky/guild/skills/protect.c
   ---------------------------------------------------------------
   Art: autorescuing of the friend, if failure autoassist
   Damage || Heal: none
   Cost: none
   Special: no real skill, the effect depends on the rescue skill. 
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int protect(string arg)
{
    object mob, other, shad;
    string who;

    if (chk_ghost(_tp))
        return 1;
    else if (objectp(mob = chk_present(_tp,arg,-1)))
    {
       if (mob == _tp)
       {
           write("You ever take care of yourself, don't you :*) ?\n");
           return 1;
       }
       else if (who = apply(call,mob,"query_protected"))
       {
           if (who == _tpr)
           {
               write("You stop taking care of "+capitalize(arg)+".\n");
               destruct(apply(call,mob,"prot_object"));
               tell_object(mob,_tpn+" stops protecting you !\n");
               return 1;
           }
           else if (other = present(who,_e(mob)))
           {
             tell_object(other,_tpn+" is now taking care of "+
             capitalize(arg)+".\n");
             destruct(apply(call,mob,"prot_object"));
           }
        }
     write("You are now taking care of "+capitalize(arg)+".\n");
     tell_object(mob,_tpn+" tries to protect you !\n");
     shad = clone_object("/players/whisky/guild/shadows/prot_shad");
     apply(call,shad,"start_shadow",mob,0,"prot_shad");
     apply(call,mob,"set_protected",_tpr);
     apply(call,mob,"set_protector",_tp);
     return 1;
  }
  return 0;
}
             

    
    
    
    

