
/* ################################################################
   #								  #
   #    		Mage locate living                        #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

doit(str,pl) {
int spnr,i;
object ob;

  if(!str) {
    ME("Locate whom ?\n");
    return 1;
  }

  spnr=MS->spellnr("locate");
  CHK_LIGHT(); CHK_GHOST()
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  OTHERS(({ TP }),TPN+" concentrates on a spell.\n");
  if((!(ob=find_living(str))) || !E(ob) || ob->query_immortal()) {
    ME("After a while of concentration you notice, that you can't find a "+
       "living\nthing called "+str+".\n");
    OTHERS(({ TP }),"And fails.\n");
    return(1);
  }

  OTHERS(({ TP }),"And succeeds.\n");
  ME("After a while of concentration you see "+ob->query_objective()+"\nat "+
     "the following place:\n\n"); 
  E(ob)->long(); 
  ob=all_inventory(E(ob));
  for(i=0;i<sizeof(ob);i++)
    if(ob[i]->short()) ME(ob[i]->short()+"\n");
  return 1;
} 
