#include "/players/bobo/clan/defines.h"

int _listen(string arg){
   object target;
   if(!arg){
      say(NAME+" tries to listen but fails.\n");
      write("You cannot just listen to air!\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target, NAME+" is listening to every word you say carefully.\n");
   write("You listen to every word that "+arg+" has to say.\n");
   say(NAME+" is listening, enrapt in "+target->QNAME+"'s conversation.\n", target);
   return 1;
   }
