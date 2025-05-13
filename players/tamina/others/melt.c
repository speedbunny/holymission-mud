
/* ################################################################
   #								  #
   #    		Mage melt weapon                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,i;
object ob,wep;

  if(!arg) {
    ME("Melt whoms weapon ?\n"); 
    return 1;
  }

  spnr=MS->spellnr("melt");
  CHK_LIGHT(); CHK_GHOST(); 
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  if((!(ob=present(arg,E(TP)))) || !living(ob)) {
    ME("You can't do that to "+arg+".\n");
    OTHERS(({ TP }),TPN+" tried to cast a spell on "+arg+" but failed.\n");
    return 1;
  }

  wep=all_inventory(ob);
  for(i=0;i<sizeof(wep);i++) {
    if(wep[i]->query_wielded()) {
      if(MELT_IT) {
        ob->stop_wielding();
        destruct(wep[i]);
        OTHERS(({ TP,ob }),TPN+" casts a spell and "+
          ob->query_name()+"'s weapon melts.\n");
        YOU(ob,TPN+" casts a spell and your weapon melts.\n");
        ME("You melt "+ob->query_name()+"'s weapon.\n");
        return 1;
      } else {
        OTHERS(({ ob }),ob->query_name()+"'s "+wep[i]->query_name()+
          " starts glowing but whithstands the magic powers.\n");
        YOU(ob,TPN+"tried to melt your weapon.\nThe "+wep[i]->query_name()+
          " starts glowing but whithstands the magic powers.\n");
        return 1;
      }
    }
  }
  ME(ob->query_name()+" has no weapon wielded.\n");
  return 1; 
}
