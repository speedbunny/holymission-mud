
/* ################################################################
   #								  #
   #    	  	   Mage disintegrate                      #
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
  spnr=MS->spellnr("disintegrate");

  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr)); 
  if(MS->chk_fiz(SPLVL(spnr),pl)) { /* it fizzled */
     if(!random(100)) {
        OTHERS(({ TP }),TPN+" tried to cast a spell but suddenly "+
           " lost control\nand was blasted by its powers.\n");
        ME("OH NO! You lost control while casting the spell.\n"+
           "The orb collapsed and you are blasted by the STRONG powers you "+
           "summoned.\n");
        TP->add_exp(TP->hit_player(random(DISINT_DAM),5));
        SOUL->set_fattack();
     }
     return 1;
  }

  ob->attacked_by(TP);
  OTHERS(({ TP,ob }),TPN+" throws a big green transparent orb in "+arg+
     "'s direction.\nAs it hits, it seems to suck "+arg+" inside.\n");
  ME("You throw a big green transparent orb in "+arg+"'s direction.\n"+
     "As it hits, it seems to suck "+arg+" inside.\n");
  YOU(ob,TPN+" throws a big green transparent orb in your direction.\n"+
     "As it hits, it seems to suck you inside.\n");
  TP->add_exp(dam=ob->hit_player(DISINT_DAM,5));
  SOUL->set_fattack();
  if(TP->query_immortal()) write("Damage (Wizinfo): "+dam+"\n");
  return 1;
}
