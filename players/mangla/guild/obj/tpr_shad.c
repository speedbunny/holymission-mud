// tpr_shad.c
// 021295: Beast : thief-proof shadow

inherit "/obj/std_shadow";

#include "/players/mangla/guild/bedefines.h"

// hp damage (shock)
#define SHOCK           (me->WIS / 4 + 8)
// sp cost (shock)
#define SHOCK_COST      30

// checking if can steal
int query_no_steal() {
    int retval;
    object thief;
    retval = me->query_no_steal(); 
    thief = ENV(PO);
    if (!retval && thief && living(thief)) {
        TELL(me, CAP(thief->RNAME) + " tries to steal from you!\n");
        if (me->SP > SHOCK_COST) {
            thief->ADDHP(-SHOCK);
            me->ADDSP(-SHOCK_COST);
            TELL(me,"Your cloak wraps about you and shocks "+
                CAP(thief->RNAME)+".\n");
            TELL(thief,"Ouch ! You try to steal from "
                +CAP(me->SNAME)+" but you got shocked!\n");
        }
    }
    return retval;
}

int tpr_shad() { 
    return 1; 
}

// end of tpr_shad.c
