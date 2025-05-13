#include "bard.h"
#define INTOXICATION_COST 35
#define INTOXICATION_LEVEL 7

int main(string str) {
    object target;
    int output, strength;
    string who;

    if(!str) { target=TP;output=0; }
    else {
	if(sscanf(str,"at %s",who)!=1) return 0;
	target=HERE(who,ENV(TP));
	output=1;
    }
    if(!target || !living(target)) {
	ME("Cast Intoxication on whom?\n");
	return 1;
    }
    CHK_GHOST();
    CHK_SP(INTOXICATION_COST);
    CHK_LVL(INTOXICATION_LEVEL);
    if(!TPWIZ) TPRSP(-INTOXICATION_LEVEL);
    strength=TPL*2+TPLL;
    if(strength>50) strength=50;
    if(output) ME("As you utter the words, "+target->QNAME+"'s blood "+
 	"magically fills with the healing liquids!\n");
     else ME("As you utter the words, you feel your own blood magically "+
	"filling with the healing liquids!\n");
    target->drink_alcohol(strength);
    if(TPWIZ) ME("WIZ INFO: alcohol strength "+strength+".\n");
    if(output) TELL(target,"You suddenly feel rather tipsy.\n");
    return 1;
}
