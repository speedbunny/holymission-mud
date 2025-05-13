
/* =============================================================== 
   Userdoc: mskills          /players/whisky/guild/skills/mskills.c
   ---------------------------------------------------------------
   Art: the feature to see all skills you can get as monk and how
        high you already learned them.
   Damage || Heal: none
   Cost: none
   Special: It's just a feature which calls the list_skills(flag)
            function in ~whisky/guild/skill_master.c which is 
            included in ~sauron/guild/room.c 
   =============================================================== */

#define _partner "/players/sauron/guild/room"


inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int mskills(string arg)
{
   object mob;
   string ret;

   if (catch(apply(call,partner,"???")))
   {
      write("Opps, you somehow can't remember your skilllevels.\n");
      return 1;
   }
   else if (apply(call,_tp,"query_guild")!=7 &&        
            apply(call,_tp,"query_property","ms_time")==-1)
            return 0;
   if (!arg)
   {
      ret = funcall(call,partner,"list_skills",_tp,1);
      write(ret);
      return 1;
   }
   else
   {
      if (!(mob=present(arg,_e(_tp))))
          write("But, there is noone called "+arg+" around.\n");
      else if (!living(mob))
          write("Lying in the sun talking to the stones :*)\n");
      else if (mob == _tp)
          write("Hmm, is nobody around here to chat ?\n");
      else 
      {
          write("You tell "+capitalize(arg)+" proudly your Monk skills.\n");
          ret = funcall(call,partner,"list_skills",_tp,1);
          tell_object(mob,
          _tpn+" proudly tells you: My Monk skills are:\n"+ret+"\n");
       }
   }
   return 1;
}
    
   
