#include "/players/sargon/define.h"

/* kick for fighters, called from the guild soul */

int kick(int no_kick, object fighter) {

  string prop_str, xmsg;
  int dam;
  object att;

  att = TP->query_attack();
  dam = TP->query_level()*5 +25;

  if(previous_object()->query_kicking()) return 0;

 

/*  can't kick as a ghost */
  if(TP->query_ghost()) {
      write("Your immaterial foot is useless!\n");
      return no_kick;
  }




  if ((att) && (E(TP)==E(att)) && (living(att))) {
     if (random((30 - TP->query_level()) * 20) < 1) {
        xmsg="YOU PLOW YOUR FOOT INTO YOUR OPPONENTS GROIN !!\n";
        dam = dam + TP->query_level() * 30;
     }

     else
        xmsg="";
     xmsg+="You kick your opponents groin.\n";
     write(xmsg);
     tell_object(att,TPN+" smashes "+TP->POS+
                 " foot in your groin.\n");
     say(TPN+" smashes "+TP->POS+
                 " foot in "+att->N+"'s groin.\n");
     if (TP)
        TP->add_exp(att->hit_player(dam));
     previous_object()->set_kicking(1);
     return 3;
  }
 
   write("You are not fighting!\n");
     return no_kick;

}
