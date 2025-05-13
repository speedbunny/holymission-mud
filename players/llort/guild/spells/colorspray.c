
/* ################################################################
   #								  #
   #    	  	   Mage colorspray                        #
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
  spnr=MS->spellnr("colorspray");

  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(TPWI/2+1);
  ADDSP(-(TPWI/2+1)); 
  CHK_FIZ(SPLVL(spnr));

  ob->attacked_by(TP);
  OTHERS(({ TP,ob }),TPN+" points at "+arg+", shooting a ray of colors at "+ob->query_possessive()+" face.\n");
  ME("You point at "+arg+", shooting a ray of colors at "+ob->query_possessive()+" face.\n");
  YOU(ob,TPN+" points at "+arg+", shooting a ray of colors at "+ob->query_possessive()+" face.\n");
  TP->add_exp(dam=ob->hit_player(COLORSPRAY_DAM,5));
  if(ob && random(2)) {
     ob->hold(SOUL,1);
     OTHERS(({ TP,ob }),capitalize(arg)+" was blinded by the ray.\n");
     ME(capitalize(arg)+" was blinded by the ray.\n");
     YOU(ob,capitalize(arg)+" was blinded by the ray.\n");
  }
  SOUL->set_fattack();
  if(TP->query_immortal()) write("Damage (Wizinfo): "+dam+"\n");
  return 1;
}
