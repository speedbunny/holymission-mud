
/* =============================================================== 
   Userdoc: accept          /players/whisky/guild/skills/accept.c
   ---------------------------------------------------------------
   Art: accepting a none human player to join the monks guild.
   Damage || Heal: none
   Cost: none
   Special: It's just the feature of a monk legend, to make it 
            possible to bring a none human player into her guild.
            Evil races as orc, troll, giant are still not allowed 
            to join. A player can only be accepted when she is 
            loged on and her level is < 10. An accepted player
            must still do the millquest to join with the risc of 
            death by touching the glowing guild banner.
   =============================================================== */

#define NO_WAY ({"orc","troll","giant"})

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
}

int accept(string whom)
{
   object mob;
   string by_whom;

    if (!whom)
    {
        write("Accept whom ?\n");
        return 1;
    }
    else if (apply(call,_tp,"query_level") < 15)
    {
        write("Only Monks >= level 15 can accept a new member.\n");
        return 1;
    }

    if (!objectp(mob = find_player(whom)) )
    {
        write("You can only accept a player, which is loged on.\n");
        return 1;
    }
    else if (apply(call,mob,"query_guild")==7)
    {
         write(capitalize(whom)+" is already guildmember silly !\n");
         return 1;
    }
    else if (apply(call,mob,"query_level") > 9)
    {
        write("A player has to have a level < 10, to be accepted.\n");
        return 1;
    }     
    else if (member_array(apply(call,mob,"query_race"),NO_WAY)!=-1)
    {
         write("But evil races are not allowed to join our guild.\n"); 
         return 1;
    }
    else if (stringp(
             by_whom = apply(call,mob,"query_property","join_monks")))
    {
        write(capitalize(whom)+" was already accepted by "+by_whom+"\n");
        return 1;
    }
    mob->add_property("join_monks",_tpr);
    write("You allow "+whom+" to join your glorious guild.\n");
    tell_object(mob,capitalize(_tpr)+" allows you to join the monks.\n");
    return 1;
}

 
