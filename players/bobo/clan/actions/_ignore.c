#include "/players/bobo/clan/defines.h"

int _ignore(string arg){
   object target;
   if(!arg){
      say(NAME+" ignores the whole damn world.\n");
      write("You decide that it's not worth it, and ignore the whole world.\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target, NAME+" no longer deigns you worthy to listen to and ignores you.\n");
   write("You are convinced that what "+arg+" has to say is stupid and so ignore "+OBJ+".\n");
   say(NAME+" totally ignores every word that "+target->QNAME+" says.\n", target);
   return 1;
   }
