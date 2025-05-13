
/* ################################################################
   #								  #
   #                  Mage meteor shower                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

doit(arg,pl) {
int spnr,i;
object ob,ev;

  if(SOUL->query_fattack()) return;

  spnr=MS->spellnr("shower");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  ME("You raise your arms and a meteor shower comes down,\n"+
     "wipeing out the whole area. BOOOOM!!\n");
  OTHERS(({ TP }),TPN+" raises "+TPPOS+
     " arms and a meteor shower comes down,\n"+
     "wipeing out the whole area. BOOOOM!!\n");

  ob=all_inventory(ev=E(TP));
  for(i=0;i<sizeof(ob);i++) 
    if(living(ob[i]) && (ob[i]!=TP)) {
      if(!MS->query_party_member(ob[i],TP)) {
        ob[i]->attacked_by(TP);
        OTHERS(({ ob[i] }),ob[i]->query_name()+" wiped out.\n");
/*
        TP->add_exp(ob[i]->hit_player(200+random(300)));
*/
        ob[i]->hit_player(200+random(300));
      }
    }
  SOUL->set_fattack();
  return 1;
}
