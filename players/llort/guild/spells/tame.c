
/* ################################################################
   #								  #
   #    		Mage tame spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(str,pl) {
int spnr;
object ob;

  if((!str)||(!(ob=present(str,E(TP))))) return;

  spnr=MS->spellnr("tame");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  if(!(TAME_CHANCE >(random(100)+1))) {
    ME("You could not tame "+str+".\n");
    OTHERS(({ TP,ob }),TPN+" tried to tame "+str+" but failed.\n");
    YOU(ob,TPN+" tried to tame you but you withstood.\n");
    return 1;
  }

  ob->stop_fight();
  ob->stop_fight();
  ob->stop_hunter(1);
  ob->set_tame(TP);

  TP->stop_fight();
  TP->stop_fight();
  TP->stop_hunter(1);

  OTHERS(({ TP,ob }),TPN+" tamed "+str+".\n");
  ME("You tamed "+str+".\n");
  YOU(ob,TPN+" tamed you.\n");
  return 1;
}
