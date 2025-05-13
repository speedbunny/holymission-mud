

/* =============================================================== 
   Userdoc: Meditate       /players/whisky/guild/skills/meditate.c
   ---------------------------------------------------------------
   Art: Special way of resting
   Damage || Heal: wisdomdepending see under: /guild/obj/blocker.c
   Cost: none
   Special: learnable by training or master / just a better rest
   =============================================================== */


inherit "/players/whisky/guild/skill_obj";
#include "gdef.h" 

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/warlord/guild/room");
}

int meditate()
{
  object victim;
  object blocker;
  mixed skill;

  if (chk_ghost(_tp))
      return 1;
  else if (objectp(victim = apply(call,_tp,"query_attack")) && 
           _e(_tp)==_e(victim))
  {
     write("But, you are fighting for your life !\n");
     return 1;
  }

  skill = apply(call,_tp,"get_skill","monk_meditate");
  
  if (!skill)
       skill = 1;
  else 
       skill = skill[0];

  if( apply(call,_tp,"query_hp") < apply(call,_tp,"query_max_hp") ||
      apply(call,_tp,"query_sp") < apply(call,_tp,"query_max_sp"))
  {
      if (chk_skill(_tp,"monk_meditate",8)==-1)  
          return 1;
  }
  if (!present("blocker",_tp))
  {
      write("You sit down in the lotus position.\n");
      say(_tpn+" sits down in the lotus position.\n",_tp);
      blocker = clone_object(_obj+"blocker");
      move_object(blocker,_tp);
      apply(call,blocker,"add_heal",skill);
      return 1;
  }
  return 0;
}
