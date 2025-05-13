
/* ################################################################
   #								  #
   #    	  	   Mage missile                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,dam;
object ob;

  if(SOUL->query_fattack()) {
    write("What ?\n");
    return 1;
  }
  if(!arg) {
    ob=TP->query_attack();
    if(ob) arg=ob->query_name();
  } else ob=present(arg,E(TP));

  if((!ob) || (!living(ob)) || (!present(ob,E(TP)))) {
    write("At whom ?\n");
    return 1;
  }
  spnr=MS->spellnr("missile");

  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr)); 
  CHK_FIZ(SPLVL(spnr));

  ob->attacked_by(TP);
  OTHERS(({ TP,ob }),TPN+" shoots a magic missile at "+arg+".\n");
  ME("You shoot a magic missile at "+arg+".\n");
  YOU(ob,TPN+" shoots a magic missile at you.\n");
  TP->add_exp(dam=ob->hit_player(MISSILE_DAM),5);
  SOUL->set_fattack();
  return 1;
}
