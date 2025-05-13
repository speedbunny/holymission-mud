
/* ################################################################
   #								  #
   #    		   Mage blast                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
    int spnr, i, dam, j;
    object ob,ev;

    if(SOUL->query_fattack()) return;

    spnr=MS->spellnr("blast");
    CHK_LIGHT(); CHK_GHOST();
    CHK_SP(SPCOST(spnr));
    ADDSP(-SPCOST(spnr));
    CHK_FIZ(SPLVL(spnr));

    ME("You raise your hands and the whole area "+
      "seems to explode.\n");
    OTHERS(({ TP }),TPN+" raises "+TPPOS+" hands and the whole area "+
      "seems to explode.\n");

    ob=all_inventory(ev=E(TP));
    j = sizeof(ob); /* 050894: Colossus. Less CPU intensive */
    if(j>20)
	j=20; /* 050894 Colossus: Eliminate too long evaluation */
    for(i=0;i<j;i++)
	if(living(ob[i]) && (ob[i]!=TP)) {
	    if(!TP->query_party_member(ob[i])) {
		ob[i]->attacked_by(TP);
		OTHERS(({ ob[i] }),ob[i]->query_name()+" blasted.\n");
		TP->add_exp(dam=ob[i]->hit_player(BLAST_DAM,5));
	    }
	}
    SOUL->set_fattack();
    return 1;
}
