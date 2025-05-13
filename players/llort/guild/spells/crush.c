
/* ################################################################
   #								  #
   #    	  	   Mage crush                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,dam;
object ob;

  if(SOUL->query_fattack()) return;

  if(!arg) {
    ob=TP->query_attack();
    if(ob) arg=ob->query_name();
  } else ob=present(arg,E(TP));

  if((!ob) || (!living(ob)) || (!present(ob,E(TP)))) {
    write("At whom ?\n");
    return 1;
  }
  spnr=MS->spellnr("crush");

  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr)); 
  CHK_FIZ(SPLVL(spnr));

  ob->attacked_by(TP);
  SOUL->set_fattack();
  OTHERS(({ TP,ob }),TPN+" forms a gigantic hand and crushes "+arg+
     " with an illusionary fist.\n");
  ME("You form a gigantic hand and crush "+arg+
     " with an illusionary fist.\n");
  YOU(ob,TPN+" forms a gigantic hand and crushes you"+
     " with an illusionary fist.\n");
  TP->add_exp(dam=ob->hit_player(CRUSH_DAM,5));
  return 1;
}
