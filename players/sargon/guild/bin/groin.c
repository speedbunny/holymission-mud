#include "/players/sargon/define.h"

int query_delay() {
  return 4;
}
 

int groin(object fighter) {

  string xmsg;
  int dam;
  object att,boot;

  att = TP->query_attack();
  dam = TP->query_level()+25;

  if(TP->query_ghost()) {
      write("Your immaterial foot is useless!\n");
      return 0;
  }

if(!(boot=TP->query_armour()[TP->query_arm_types("boot")])) {
      write("You need boots to kick effectively!\n");
      return 1;
  }

if(!att=TP->query_attack()){
        write("You are not fighting.\n");
        return 1;
  }

if ((att) && (E(TP)==E(att)) && (living(att))) {
dam = dam;
     }

xmsg="";
xmsg+="You kick your opponents groin.\n";
     write(xmsg);{
     tell_object(att,TPN+" smashes "+TP->POS+
                 " foot in your groin.\n");
     say(TPN+" smashes "+TP->POS+
                 " foot in "+att->N+"'s groin.\n");
TP->add_exp(att->hit_player(dam));
return 1;
  }

}
