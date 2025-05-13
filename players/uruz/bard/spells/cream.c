#include "bard.h"
#define CREAM_COST 20
#define CREAM_LEVEL 3

int main(string str) {
    string who, what;
    object target;
    int dam;

    if(!str) return 0;
    if(sscanf(str,"%s at %s",what,who)!=2 && str!="pie" && str!="pie at") return 0;
    if(what && what!="pie") return 0;
    CHK_GHOST();
    CHK_LVL(CREAM_LEVEL);
    CHK_SP(CREAM_COST);
    if(!who && !TPATT) {
	ME("Cast Cream Pie at whom?\n");
	return 1;
    }
    if(!who) target=TPATT;
    else target=HERE(who,ENV(TP));
    if(!target || !living(target)) {
	ME("Cast Cream Pie at whom?\n");
	return 1;
    }
    if(target==TP) {
	ME("You hit yourself in the face with a cream pie!\n");
	say(TPN+" hits "+TPOBJ+"self in the face with a cream pie!\n");
	return 1;
    }
    target->attacked_by(TP);
    ME("You throw a cream pie into "+target->QNAME+"'s face!\n");
    say(TPN+" throws a cream pie into "+target->QNAME+"'s face!\n",target);
    TELL(target,TPN+" throws a cream pie into your face!\n");
    dam=TPCHR+RAN(10);
    target->HIT(dam);
    TP->XP(dam);
    target->hold(TP,3);
    TPRSP(CREAM_COST);
    return 1;
}
