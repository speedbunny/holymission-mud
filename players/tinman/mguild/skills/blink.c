


/* =============================================================== 
   Userdoc: Blink          /players/whisky/guild/skills/blink.c
   ---------------------------------------------------------------
   Art: Protection via jumping fast around the opponent
   Damage || Heal: avoiding damage from the 2 combat round on at
                   any 3 (blinking) rounds.
   Cost: 30
   Special: learnable by training or master / when a player blinks
            she can be held / extremly expensive skill for high levels /
            a blinking player can't escape the fireshield damage.
   =============================================================== */
 
#define COST _cost(30) 
#define _partner "/players/sauron/guild/room"

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}

int blink(string arg)
{
    object shad;
   
    if (arg) 
        return 0;
    else if (chk_ghost(_tp))
        return 1;
    else if (apply(call,_tp,"shad_id","blink"))
    {
        write("You are already vibrating !\n");
        return 1;
    }
    else if (_tps < COST)
    {
        write("You don't feel agil enough to vibrate !\n");
        return 1;
    }
    
    write("You try to vibrate !\n");

    if (!chk_skill(_tp,"monk_blink",8))
    {
        apply(call,_tp,"restore_spell_points",-(1+COST)/2);
        return 1;
    }
    say(_tpn+" starts to vibrate \n",_tp);
    shad = clone_object(_shad+"blink_shad");
    apply(call,shad,"set_effect_msg","blink");
    funcall(call,shad,"start_shadow",_tp,(300 + 
                      random(_tpc * 13)),"blink");
    apply(call,_tp,"restore_spell_points",-COST);
    return 1;
}
        
    

