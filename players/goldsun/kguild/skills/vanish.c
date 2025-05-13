
/* dead */

#define COST  0 
#include "chk_att.h"

int vanish(string arg)
{
   object *inv;
   int i, sz, chk, prop;
   mixed skill;


    if (arg) 
        return 0; 
    else if (apply(call,_tp,"query_ghost"))
    {
        write("You can't do this in your immateral state !\n");
        return 1; 
    }
   
/*   skill = funcall(call,_tp,"get_skill","monk_dead");

    if (!skill)
        skill = 1;
    else 
        skill = skill[0];
 */   
    write("You fall down acting dead !\n");

//    if (!_suc(skill))
    {
      say(_tpn+" falls down acting dead !\n");
//      if (_adv(skill,6))
  //        apply(call,_partner,"raise_skill",_tp,"monk_dead",1);
      return 1;
    }
    
    inv = all_inventory(_e(_tp));

    for( sz=sizeof(inv), i = 0; i < sz; i++ )
    {    
         if (living(inv[i]))
         {
            chk = random(apply(call,inv[i],"query_int")/2);

// this is important that the victim learns from this trick

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
            
            
        
       
       

