#include "/players/sargon/define.h"


int but(int no_but, int butt, object fighter) {

  string prop_str, xmsg;
  int dam;
  object att,helmet;

  att = TP->query_attack();
  dam = TP->query_level()*3 +25;

  if(previous_object()->query_butting()) return 0;

int butt;

void reset_butt() {
    butt = 0;
}

void set_butting() {
    butt = 1;
    call_out("reset_butt", 0, 1);
    return;
}

int query_butting() {
    return butt;
}

/* can't but as a ghost */
  if(TP->query_ghost()) {
      write("Your immaterial head is useless!\n");
      return no_but;
  }

/* need to use helmets */
  if(!(helmet=TP->query_armour()[TP->query_arm_types("helmet")])) {
      write("You need a helmet to do that!\n");
      return no_but;
  }

/* no_fight area  */
  prop_str = E(TP)->query_property();
  if(prop_str == "no_fight") {
    E(TP)->try_attack(att);
    return no_but;
  }

/* Head butting very quickly can hurt */
   if(no_but = 0) {
     if(random(2)) {
       write("Ouch, that was too early! You hurt yourself!\n");
        TP->reduce_hit_point(random(4) - helmet->armour_class());
     } 
     else
        write ("You have to wait a while !\n");
     return no_but;
  }

  if ((att) && (E(TP)==E(att)) && (living(att))) {
     if (random((30 - TP->query_level()) * 20) < 1) {
        xmsg="VICIOUS HIT !!\n";
        dam = dam + TP->query_level() * 20;
     }
     else
        xmsg="";
     xmsg+="You smash your head in the opponents face.\n";
     write(xmsg);
     tell_object(att,TPN+" smashes "+TP->POS+
                 " head in your face.\n");
     say(TPN+" smashes "+TP->POS+
                 " head in "+att->N+"'s face.\n");
     if (TP)
        TP->add_exp(att->hit_player(dam));
     previous_object()->set_butting(1);
     return 3;
  }
  write("You are not fighting!\n");
  return no_but;
}


