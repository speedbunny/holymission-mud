
/* find : Its a skill of a monk with protector status or higher
   a normal monk can't use this skill, but it's necessary for a
   protector to find her followers or victims of the guild. */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
}

int find(string arg)
{
    object mob;

    if (!arg)
    {
        write("Whom do you want to find ?\n");
        return 1;
    }
    else if (chk_ghost(_tp))
        return 1;

    mob = find_living(arg);

    if (objectp(mob) && objectp(environment(mob)) &&
        (apply(call,this_player(),"query_immortal") || 
         !apply(call,mob,"query_immortal")) )
    {
       apply(call,environment(mob),"long");
       write(capitalize(apply(call,mob,"query_real_name"))+"\n");
       return 1;
    }
    write("Your telepatic feature couldn't find "+arg+"\n");
    return 1;
 }

    
