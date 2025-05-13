
#include "defs.h"

mixed chk_attack(string arg,int cost)
{
   object victim;

       if (!stringp(arg))
           victim = apply(call,_tp,"query_attack");
       else       
           victim = present(arg,_e(_tp));

       if (apply(call,_tp,"query_ghost"))
       {
          write("You can't do that in your immaterial state !\n");
          return 1;
       }
       else if (cost > _tps)
       {
          write("You are too low on power !\n");
          return 1;
       }
       else if (objectp(victim) && _e(victim) == _e(_tp)  && living(victim))
       {
           if (victim == _tp)
           {
              write("You try to hit yourself, but you fall on your but !\n");
              return 1;
          }
          else 
           return victim;
       }
     write("You can't attack someone who is not here or already dead !\n");
     return 1;
}

       
        
