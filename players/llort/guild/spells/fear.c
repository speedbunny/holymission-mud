
/* ################################################################
   #								  #
   #    		Mage fear spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object ob;

  if(!arg) {
    ME("Fear whom ?\n"); 
    return 1;
  }

  spnr=MS->spellnr("fear");
  CHK_LIGHT(); CHK_GHOST(); 
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  if((!(ob=present(arg,E(TP)))) || (TPL<ob->query_level() &&
       random(ob->query_level()-TPL))) {
    OTHERS(({ TP,ob }),TPN+" made BOOO at "+arg+
       " but "+(ob?ob->query_objective():"it")+" doesn't seem interested.\n");
    ME("You try to fear "+arg+" but "+(ob?ob->query_objective():"it")+
       " seems to withstand your attempt.\n");
    if(ob) YOU(ob,TPN+" makes some magical gestures and cries BOOO at you.\n");
    return 1;
  }

  YOU(ob,"You feel a sudden fear overcomes you.\n");
  ob->run_away();
  if(!present(ob,E(TP))) {
    OTHERS(({ TP,ob }),TPN+" makes some gestures and "+ob->query_name()+
       " runs away in panic.\n");
    ME("You fear "+arg+" and "+ob->query_objective()+" runs away in panic.\n");
  } else { 
    OTHERS(({ TP,ob }),ob->query_name()+" attacks "+TPN+".\n");
    ME(ob->query_name()+" attacks you.\n");
    ob->attack_object(TP);
  }
  return 1;
}
