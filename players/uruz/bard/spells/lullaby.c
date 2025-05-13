#include "bard.h"
#define LULLABY_COST 50
#define LULLABY_LEVEL 10

int main(string str) {
    object target;
    string who;

    if(!str && !TPATT) {
	ME("Cast Lullaby at whom?\n");
	return 1;
    }
    CHK_GHOST();
    CHK_SP(LULLABY_COST);
    CHK_LVL(LULLABY_LEVEL);
    if(!str) target=TPATT;
    else if(sscanf(str,"at %s",who)!=1) target=TPATT;
    if(who) target=HERE(who,ENV(TP));
    if(!target || !living(target)) {
	ME("Cast Lullaby at whom?\n");
	return 1;
    }
    if(target==TP) {
	ME("You do not want to fall asleep!\n");
	return 1;
    }
    if(!TPWIZ) TPRSP(-LULLABY_COST);
    ME("You strum a soothing, soft lullaby.\n");
    say(TPN+" strums a soothing, soft lullaby.\n", target);
     TELL(target, TPN+" strums a soothing, soft lullaby. You are unable "+
	"to keep your eyes open...\n");
    target->hold(TP,TPCHR+1);
    return 1;
}
