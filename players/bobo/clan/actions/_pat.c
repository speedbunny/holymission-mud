#include "/players/bobo/clan/defines.h"

int _pat(string arg){
   object target;
   if(!arg){
      say(NAME+" tries to pat "+OBJ+" on the head but "+PRON+" can't reach that high.\n");
      write("You try to pat yourself on the head but fail miserably.\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target, NAME+" pats you on the head with a smile.\n");
   write("You pat "+arg+" on the head, smiling, trying to undersatand.\n");
   say(NAME+" pats "+target->QNAME+" on the head.\n", target);
   return 1;
   }
