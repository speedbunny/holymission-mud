#include "/players/bobo/clan/defines.h"

int _chide(string arg){
   object target;
   if(!arg){
      say(NAME+" looks around for someone to chide but doesn't see anyone worth it.\n");
      write("No one around here is worthy of your attention.\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target, NAME+" chides you for your ineptitude.\n");
   write("You chide "+arg+" for "+POSS+" ineptitude.\n");
   say(NAME+" chides "+target->QNAME+" for their ineptitude.\n", target);
   return 1;
   }
