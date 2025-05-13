/* MAGE FIREBALL.C - Programmed by Llort */
/* 270993: Ethereal Cashimor: optimized fireball-loop. */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
    int spnr, i, dam, j;
    object ob,ev;

    if(SOUL->query_fattack()) {
	ME("What ?\n");
	return 1;
    }

    spnr=MS->spellnr("fireball");
    CHK_LIGHT(); CHK_GHOST();
    CHK_SP(SPCOST(spnr));
    ADDSP(-SPCOST(spnr));
    CHK_FIZ(SPLVL(spnr));

    ME("You set a ball of fire in the area.\n");
    OTHERS(({ TP }),TPN+" sets a ball of fire in the area.\n");

    ob=all_inventory(ev=E(TP));
    j=sizeof(ob); /* 050894 Colossus: Makes it less CPU intensive */
    if(j>20)
	j=20; /* 050894 Colossus: Eliminate too long evaluation */
    TP->add_exp(j*5);
    for(i=0;i<j;i++)
	if(living(ob[i]) && (ob[i]!=TP)) {
	    if(!TP->query_party_member(ob[i])) {
		ob[i]->attacked_by(TP);
		OTHERS(({ ob[i] }),ob[i]->query_name()+" is hit.\n");
	    }
	}
    SOUL->set_fattack();
    return 1;
}



