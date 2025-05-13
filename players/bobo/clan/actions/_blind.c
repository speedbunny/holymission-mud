#include "/players/bobo/clan/defines.h"

int _blind(string arg){
   object target;
   if(!arg){
      say(NAME+" blinds himself with his amulet.\n");
      write("You blind yourself with your amulet inadvertantly.\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target,NAME+" reflects the light of the sun with "+POSS+
               " amulet and blinds you.\n");
   write("You blind "+arg+" in hopes of teaching "+target->QNAME+
         " some manners.\n");
   say(target->QNAME+" stands there stupidly as "+target->QPRON+" gropes "+
       "around without sight.\n", target);
   return 1;
   }
