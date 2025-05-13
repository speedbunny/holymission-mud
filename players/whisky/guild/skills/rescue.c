

/* =============================================================== 
   Userdoc: Rescue          /players/whisky/guild/skills/rescue.c
   ---------------------------------------------------------------
   Art: Attacker change 
   Damage || Heal: none 
   Cost: none
   Special: learnable by training or master / a rescuing player 
            protects the friend by changing the attacker to get
            the victims hits herself.
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int rescue(string arg)
{
     object mob, vic;

     if (objectp(mob = chk_present(_tp,arg,0)))
     {
           
         if (mob == _tp)
         {
             write("Rescuing yourself ?\n");
             return 1;
         }
         else if (!objectp(vic = mob->query_attack()))
         {
             write("You can only rescue someone under attack !\n");
             return 1;
         }
         else if (vic == _tp)
         {
             write("Rescuing your victim ?\n");
             return 1;
         }
         else if (!living(vic))
         {
             write("You are confused !\n");
             return 1;
         }

         if (!chk_skill(_tp,"monk_rescue",6))
         {
             write("You fail to rescue "+arg+".\n");
             return 1;
         }
         write("You make an impressive fight move to rescue "+arg+".\n");
         say(_tpn+" makes an impressive fight move !\n",_tp,mob);
         tell_object(mob,_tpn+" rescues you heroically !\n");
         _tp->attack_object(vic);
         vic->change_attacker(_tp);
         return 1;
    }
    return 0;
}

