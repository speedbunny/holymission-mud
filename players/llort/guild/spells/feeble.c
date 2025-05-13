
/* ################################################################
   #								  #
   #    		Mage feeble monster                       #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(str,pl) {		/* Costs 30 spellpoints */
object wat,*ob;
int nwat,spnr;
int i,j,sz;

  spnr=MS->spellnr("feeble");
  CHK_LIGHT(); CHK_GHOST();

  if (!str) {
    ME("Feeble mind whom ?\n");
    return 1;
  }

  if (!(wat=present(str,E(TP)))) return;	/* Feeble at what ? */

  if (!living(wat)) {
    ME("The "+str+" seems to ignore you.\n");
    OTHERS(({ TP }),TPN+" tries to cast a spell on "+str+" but ist seems "+
      "to ignore "+TP->objective()+".\n");
    return 1;
  }

  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  ME("You concentrate your psychic energies.\n");
  OTHERS(({ TP,wat }),TPN+" concentrates on "+str+".\n");
  YOU(wat,TPN+" concentrates on you.\n");
  i = FEEBLE_CHANCE;
  if (random(101)>i) {
    ME("You lose your concentration.\n");
    OTHERS(({ TP }),"But loses "+TPPOS+" concentration.\n");
    
/* If losing concentration, the attacker can hit back ! */
    if (random(4)) {
      ME(wat->short()+" hits you another time !\n");
      wat->attack_object(TP);
    }
    return 1;
  }

/* Search a new victim for "wat" to attack :-) */

  ob=all_inventory(E(TP));
  sz=sizeof(ob);
  nwat=allocate(sz);
  j=-1;
  for (i=0;i<sz;i++)
  if (living(ob[i]) && ob[i]!=TP && ob[i]!=wat &&
      !ob[i]->query_ghost() && !ob[i]->query_immortal())
	  nwat[++j]=i;

  if (j<0) {		/* Couldn't find an other attacker */
    ME("But there is nobody to attack except you.\n");
    OTHERS(({ TP,wat }),"But there is nobody to attack except "+TPN+".\n");
    wat->attack_object(TP);
  } else {
    i=random(j+1);	/* This now is the new attacked object */
    OTHERS(({ TP }),TPN+" confused "+wat->query_name()+".\n");
    ME("You succeed in confusing "+wat->query_name()+".\n");
    SAY(wat->query_name()+" suddenly starts to attack "+
      ob[nwat[i]]->query_name()+" !\n");
    wat->attack_object(ob[nwat[i]]);
  }
  return 1; 
}
