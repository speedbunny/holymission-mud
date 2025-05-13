

/* =============================================================== 
   Userdoc: Consider       /players/whisky/guild/skills/consider.c
   ---------------------------------------------------------------
   Art: better info about victim, big steps, should I attack or better
        not, better armour ? , better weapons ?
   Damage || Heal: none
   Cost: none
   Special: no skill, but will learnable by training or master in future
   =============================================================== */

#define COST 0

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
}

int consider(string arg)
{
   object mob;
   string name, poss, pron;
   int level, help, hp, ac, wc, dex, str;


   if (objectp(mob = chk_present(_tp,arg,COST))) 
   {
       name = apply(call,mob,"query_name");
       poss = apply(call,mob,"query_possessive");
       pron = apply(call,mob,"query_pronoun");
       level = apply(call,mob,"query_level");
       hp = apply(call,mob,"query_hp");
       dex = apply(call,mob,"query_dex");
       str = apply(call,mob,"query_str");

       if (apply(call,mob,"query_ac") > apply(call,mob,"query_n_ac"))
           ac = apply(call,mob,"query_ac");
        else
         ac = apply(call,mob,"query_n_ac");
        if (apply(call,mob,"query_wc") > apply(call,mob,"query_n_wc"))
            wc = apply(call,mob,"query_wc");
         else
            wc = apply(call,mob,"query_n_wc");

       if (mob == _tp)
       {
           write("Yep, thats you who else can be so heavy :*)\n");
           return 1;
        } 
        else if (apply(call,mob,"query_player"))
        {
            write("Would you like to borrow a cross and a shovel ?\n");
            return 1;
        }
       write("You consider "+name+" carefully:\n\n");
       say(_tpn+" considers "+name+" carefully.\n",_tp,mob);

       if (_tpl > level)
           write("You think that this could be an easy opponent.\n");
       else if ( (_tpl*2) > level )
           write("You think that this could be a really hard fight.\n");
       else if ( (_tpl*3) > level )
           write("You think that you might loose this fight.\n");
       else 
           write("You think that this opponent is your sure death.\n");

       if (apply(call,_tp,"query_hp") > hp)
           write(name+" seems to be in a worse condition than you.\n");
       else if ( (apply(call,_tp,"query_hp") * 3 ) > hp)
           write(name+" seems to be in a bit better condition than you.\n");
       else if ( (apply(call,_tp,"query_hp") * 9 ) > hp)
           write(name+" seems to be in a better condition than you.\n");
       else 
           write(name+" seems to be in a much better condition than you.\n");

       if (_tpst > str)
           write(capitalize(pron)+" seems to be weaker and ");
       else if ( (_tpst + _tpst/9) > str )
           write(capitalize(pron)+" seems equally strong and ");
       else if ( (_tpst * 3 ) > str)
           write(capitalize(pron)+" seems to be stronger and ");
       else 
           write(capitalize(pron)+" seems to be much stronger and ");

       if (_tpd > dex)
           write("less agile than you.\n");
       else if ( (_tpd + _tpd/9)  > dex )
           write("as agile as you.\n");
       else if ( (_tpd * 3 ) > dex)
           write("more agile than you.\n");
       else 
           write("much more agile than you.\n");

       if (apply(call,_tp,"query_ac") > ac)
           write(capitalize(poss)+" armour seems to be worse and ");
       else if ( (apply(call,_tp,"query_ac")*3/2) > ac)
           write(capitalize(poss)+" armour seems to be a bit better and ");
       else if ( (apply(call,_tp,"query_ac")*2) > ac)
           write(capitalize(poss)+" armour seems to be better and ");
       else
           write(capitalize(poss)+" armour seems to be much better and ");

       if (apply(call,_tp,"query_wc") > wc)
           write(poss+" weapons seem to be worse.\n");
       else if ( (apply(call,_tp,"query_wc")*3/2) > wc)
           write(poss+" weapons seem to be a bit better.\n");
       else if ( (apply(call,_tp,"query_wc")*2) > wc)
           write(poss+" weapons seem to be better.\n");
       else
           write(poss+" weapons seem to be much better.\n");
      return 1;
    }
  return 0;
}

