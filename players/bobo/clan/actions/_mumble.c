#include "/players/bobo/clan/defines.h"

int _mumble(string arg){
   object target;
   if(!arg){
      say(NAME+" mumbles something about everyone being a dumb ass.\n");
      write("You let the whole world know that they are a bunch of dumbasses.\n");
      return 1;
      }

   else

   target = present(arg,environment(TP) );
   if(!target) return printf(capitalize(arg) +" is not here worshipper.\n"),1;
   tell_object(target, NAME+" mumbles something but all you make out is your name and dumbass.\n");
   write("You quietly let "+arg+" know that "+PRON+" is a dumbass.\n");
   say(NAME+" mumbles something, almost to "+OBJ+"self.\n", target);
   return 1;
   }
