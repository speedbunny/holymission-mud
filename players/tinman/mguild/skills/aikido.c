

/* =============================================================== 
   Userdoc: aikido          /players/whisky/guild/skills/aikido.c
   ---------------------------------------------------------------
   Art: Protection (self)
   Damage || Heal: reduces "only" weapon damage, type 0 by 33%
   Cost: 8
   Special: learnable by training or master / cheap cause standard-
            feature even for newbies.
   =============================================================== */

#define COST _cost(8) 

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int aikido()  
{
  object shad;
  
    if (chk_ghost(_tp))
        return 1;

    else if (_tps < COST)
    {
        write("You are too low on power for this action.\n");
        return 1;
    }
    else if (apply(call,_tp,"shad_id","aikido") == 1)
    {
        write("But you are already concentrated on aikido !\n");
        return 1;
    }    
    else 
    {
        write("You try to concentrate on aikido !\n");
        if (chk_skill(_tp,"monk_aikido",2))
        {
            shad = clone_object(_shad+"aik_shad");
            apply(call,shad,"set_effect_msg","aikido");
            apply(call,shad,"start_shadow",_tp,(1500+_tpw * 25),"aikido");
 
        }
        apply(call,_tp,"restore_spell_points",-COST);
        return 1;
    }
    return 1;
}


