/* ===============================================================
  Meditate  
 Art: Special way of resting
   Damage || Heal: wisdom and level depending see under: /guild/obj/blocker.c
   Cost: none
   =============================================================== */

#include "/players/tinman/defs.h"

int main()
{
  object victim;
  object blocker;
  mixed amount;
  amount = TP->query_level();

if(TP->query_ghost()) {
        write("Your ghostly body is not build for this attempt.\n");
        return 1;
    }

if((victim = TP->query_attack()) && environment(TP) == environment(victim))
  {
     write("But, you are fighting for your life !\n");
     return 1;
  }

  if (!present("blocker",TP))
  {
      write("You sit down in the lotus position.\n");
      say(TP->NAME+" sits down in the lotus position.\n",TP);
      blocker = clone_object(GOBJ+"blocker");
      move_object(blocker,TP);
		blocker->add_heal(amount);
      return 1;
  }
  return 0;
}
