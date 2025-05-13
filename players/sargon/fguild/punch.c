#include "/players/sargon/define.h"

/* punch for fighters, called from the guild soul */

int punch(int no_punch, object fighter) {

  string prop_str, xmsg;
  int dam;
  object att;

  att = TP->query_attack();
  dam = TP->query_level()*5 +25;

  if(previous_object()->query_punching()) return 0;

 

/*  can't punch as a ghost */
  if(TP->query_ghost()) {
      write("Your immaterial hand is useless!\n");
      return no_punch;
  }

/* can't be wielding a weapon 
  if(!(weapon=TP->query_weapon()[TP->query_arm_types("sword")])) {
      write("You can't be wielding a weapon to punch!\n");
      return no_punch;
  }
*/
/* no_fight area  
  prop_str = E(TP)->query_property();
  if(prop_str == "no_fight") {
    E(TP)->try_attack(att);
    return no_punch;
  }
*/
/* Punching too fast is not good 
   if(no_punch = 0) {
     }
     else
        write ("You have to wait a while !\n");
     return no_punch;
  }
*/
  if ((att) && (E(TP)==E(att)) && (living(att))) {
     if (random((30 - TP->query_level()) * 20) < 1) {
        xmsg="YOU PLOW YOUR FIST INTO YOUR OPPONENTS FACE !!\n";
        dam = dam + TP->query_level() * 30;
     }

     else
        xmsg="";
     xmsg+="You punch your opponents face.\n";
     write(xmsg);
     tell_object(att,TPN+" smashes "+TP->POS+
                 " fist in your face.\n");
     say(TPN+" smashes "+TP->POS+
                 " fist in "+att->N+"'s face.\n");
     if (TP)
        TP->add_exp(att->hit_player(dam));
     previous_object()->set_punching(1);
     return 3;
  }
 
   write("You are not fighting!\n");
     return no_punch;

}

