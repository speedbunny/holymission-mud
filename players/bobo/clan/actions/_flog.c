#include "/players/bobo/clan/defines.h"

int _flog(string arg){
   object target;
   if(!arg){
      say(NAME+" flogs "+POSS+" for his pigheaded actions.\n");
      write("You flog yourself pigheadedly.\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target, NAME+" flogs you for your blatant ignorance.\n");
   write("You flog "+arg+" for "+POSS+" blatant ignorance.\n");
   say(target->QNAME+" stands there as "+NAME+" flogs "+target->QOBJ+" for "+
   target->QPOSS+" ignorance.\n", target);
   return 1;
   }
