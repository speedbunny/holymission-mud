

/* =============================================================== 
   Userdoc: Teach           /players/whisky/guild/skills/teach.c
   ---------------------------------------------------------------
   Art: Learning skills to a friend
   Damage || Heal: none
   Cost: 1/9 of all the power per try 
   Special: No real skill, its just a learning by showing / the 
            friend must have a skillbase to get teached / the teach  
            gets harder the higher the friends skill is / tought can
            be a maximum of 2/3 of the monks own skill. / very slow.
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

#define COST  (9+apply(call,_tp,"query_max_sp"))/9 

void reset(int flag)
{
     ::reset(flag);
     if (flag==0)
        set_partner("/players/sauron/guild/room");
} 

int teach(string arg)
{
    string whom, what;
    mixed mskill, pskill;
    object mob;
    int mali;

    if (!arg || sscanf(arg,"%s %s",whom,what)!=2)
    {
        write("Teach whom what ?\n");
        return 1;
    }
    if (!objectp(mob = chk_present(_tp,whom,COST)))
        return 1;
    else if (mob == _tp)
    {
        write("The harder you try, the more sober you get.\n");
        return 1;
    }
    else if(!interactive(mob)) {
        printf("You don't think that %s is paying any attention.\n",
               capitalize(whom));
        return 1;
    }
    mskill = funcall(call,_tp,"get_skill","monk_"+what);
    pskill = funcall(call,mob,"get_skill","monk_"+what); 

    if (apply(call,mob,"query_guild")==7)
        mali = 1;
    else 
        mali = 2;
    
    if (!mskill)
    {
        write("But you don't know of that skill.\n");
        return 1;
    }

    if (!pskill)
         pskill = 0;
    else 
         pskill = pskill[0];

    if (!pskill && mali==3)
    {
        write("But, "+
               apply(call,mob,"query_name")+
               " is no Monk and has no sense of that skill.\n");
        return 1;
              
    }
    if (mskill[0] < pskill)
    {
        write("You better should take lessons from "+
              capitalize(whom)+".\n");
        return 1;
    }
    else if (mskill[0] < 30)
    {
        write("You should better raise your own skills before.\n"); 
        return 1;
    }
    else if (mskill[0]*2/3 < pskill)
    {
        write(capitalize(whom)+" is too good in that "+what+" skill "+
              "to be taught by you.\n");
        return 1;
    }
    else if (random(50*mali) > ((mskill[0]-pskill)/2) || 
             !random((10+mob->query_int())/5))
    {
        say(_tpn+" shows "+mob->query_name()+" "+_tpp+ 
            " "+what+" skill.\n",mob,_tp);
        write(capitalize(whom)+" looks confused.\n");
        tell_object(mob,_tpn+" shows you "+_tpp+" "+what+" skill.\n"+
                    "You are confused.\n");
    }         
    else
    {
        say(_tpn+" shows "+mob->query_name()+" "+_tpp+ 
            " "+what+" skill.\n",mob,_tp);
        write("You feel you have improved "+capitalize(whom)+
              "'s "+what+" skill.\n");
        tell_object(mob,_tpn+" shows you "+_tpp+" "+what+" skill.\n"+
                   "You feel your skill improved.\n");
        funcall(call,partner,"raise_skill",mob,"monk_"+what,1);
    }
    apply(call,_tp,"restore_spell_points",-COST);
    return 1;
}

        


