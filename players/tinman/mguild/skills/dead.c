

/* =============================================================== 
   Userdoc: Dead           /players/whisky/guild/skills/dead.c
   ---------------------------------------------------------------
   Art: Acting dead, to stop the victim attacking you
   Damage || Heal: none
   Cost: none
   Special: learnable by training or master / the victim notices
            when you once fooled him. The change is then far lower
            to use this trick.
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
        set_partner("/players/sauron/guild/room");
}
     

int dead(string arg)
{
   object *inv;
   int i, sz, chk, prop;


    if (arg) 
        return 0; 

    else if (chk_ghost(_tp))
         return 1;
    
    write("You fall down acting dead !\n");

    if (!chk_skill(_tp,"monk_dead",6))
    {
      say(_tpn+" falls down acting dead !\n");
      return 1;
    }
    
    inv = all_inventory(_e(_tp));

    for( sz=sizeof(inv), i = 0; i < sz; i++ )
    {    
         if (living(inv[i]))
         {
            chk = random(apply(call,inv[i],"query_int")/2);
            prop = apply(call,inv[i],"query_property","cact_dead") + 1;
           
            if (inv[i]!=_tp)
            { 
               if ( (chk + prop) < (_tpi))
               {
                  tell_object(inv[i],_tpn+" died.\n");
                  apply(call,inv[i],"add_property","cact_dead",(prop+chk));
                       
               }
               else 
               {
                  tell_object(inv[i],_tpn+" falls down acting dead !\n");
                  if (prop && chk < random(_tpi/2) )
                     apply(call,inv[i],"remove_property","cact_dead");
               }
            }

            if (_tp==apply(call,inv[i],"query_attack") && ((chk+prop) < _tpi) )
            {
               apply(call,inv[i],"stop_fight");
               apply(call,inv[i],"stop_fight");
               apply(call,inv[i],"stop_hunter",1);
           }
        }
    }
    apply(call,_tp,"stop_fight");
    apply(call,_tp,"stop_fight");
    apply(call,_tp,"stop_hunter",1);
    return 1;      
}
            
