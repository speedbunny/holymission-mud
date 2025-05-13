

/* =============================================================== 
   Userdoc: Feet          /players/whisky/guild/skills/feet.c
   ---------------------------------------------------------------
   Art: damage type 0 (weaponhit)
   Damage || Heal: 5 + dex * 3 /2
   Cost: none because of low damage and weak damagetype
   Special: learnable by training or master
   =============================================================== */

#define DAM  _dam(5 + _tpd * 3 /2)
#define COST  0 
#define HOW ({"right foot","left foot","right knee","left knee"})

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
        set_partner("/players/sauron/guild/room");
}

int feet(string arg)
{
   object mob;
   string name;

  
    if (objectp(mob = chk_attack(_tp,arg,-100)))
    {
        name = apply(call,mob,"query_name");
        apply(call,_tp,"attack_object",mob); 
        
       if (!chk_skill(_tp,"monk_feet",1))
       {
           write("You try to hit "+name+" with your "+HOW[random(4)]+
                 " but miss.\n");
           say(_tpn+" tries to hit "+name+" with "+_tpp+" "+HOW[random(4)]+
                 " but misses.\n",mob,_tp);
           tell_object(mob,_tpn+" tries to hit you with "+_tpp+
                 " "+HOW[random(4)]+" but misses.\n");

           return 1;
        }
        write("You hit "+name+" with your "+HOW[random(4)]+".\n");
        say(_tpn+" hits "+name+" with "+_tpp+" "+HOW[random(4)]+".\n",mob,_tp);
        tell_object(mob,_tpn+" hits you with "+_tpp+" "+HOW[random(4)]+".\n");

        if (mob)
            apply(call,mob,"hit_player",DAM,0);
        return 1;
   }
   return 0;
}
