#include "bard.h"
#define SEDUCTION_COST 25
#define SEDUCTION_LEVEL 3

int main(string str) {
    object target;
    string who;

    if(!str && !TPATT) {
	ME("Cast Seduction at whom?\n");
	return 1;
    }
    CHK_GHOST();
    CHK_LVL(SEDUCTION_LEVEL);
    CHK_SP(SEDUCTION_COST);
    sscanf(str,"at %s",who);
    if(!who) target=TPATT;
    else target=HERE(who,ENV(TP));
    if(!target || !living(target)) {
	ME("Cast Seduction at whom?\n");
	return 1;
    }
    if(target==TP) {
	ME("You do not want to seduce yourself.\n");
	return 1;
    }
    if(TPSEX==target->QSEX) {
	ME("Very doubtful you could charm your own sex!\n");
	return 1;
    }
    if(!TPWIZ) TPRSP(-SEDUCTION_COST);
    ME("You strum a loving ballad to "+target->QNAME+".\n");
    say(TPN+" strums a sentimental ballad to "+target->QNAME+", who falls "+
	"helplessly in love with "+TPN+".\n");
     TELL(target, TPN+" sings a sweet ballad to you. You fall helplessly "+
	"in love with "+TPN"+.\n");
    if(target->QNPC) {
	target->set_wimpy(0);
	target->set_aggressive(0);
    }
    target->RSP(-100);
    TELL(target,"You sigh at "+TPN+"'s sign of affection.\n");
    say(target->QNAME+" sighs happily.\n");
    ME(target->QNAME+" sighs happily.\n");
    TP->HEAL(10);
    return 1;
}
