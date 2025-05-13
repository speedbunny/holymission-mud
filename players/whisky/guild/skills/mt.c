
/* =============================================================== 
   Userdoc: mt                   /players/whisky/guild/skills/mt.c
   ---------------------------------------------------------------
   Art: Mindtransfer (psychonic feature)
   Damage || Heal: none
   Cost: 2
   Special: This is a feature, which makes the same as the tell
            command of the player. But is more natural. 
   =============================================================== */

#define COST 2

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
}

int mt(string arg)
{
    string whom, what;
    object mob;

    if (!arg)
         return 0;
    else if (sscanf(arg,"%s %s",whom,what)!=2)
    {
       write("mt whom what ?\n");
       return 1;
    }
    else if (apply(call,this_player(),"query_sp") < COST)
    {
       write("You are too low on power !\n");
       return 1;
    }
    else if (!objectp(mob = find_living(whom)))
    {
       write("You cant find anyone called "+whom+" !\n");
       return 1;
    }
    write("You conzentrate on "+whom+".\n");
    ltell(mob,"thinks:",":*) "+what+"\n",_tp);
    apply(call,this_player(),"restore_spell_points",-COST);
    return 1;
}
