#include "bard.h"
#define UNCONTROLLABLE_COST 40
#define UNCONTROLLABLE_LEVEL 22

int main(string str) {
    object target, laugher;
    string what, who;
    int time;

    if(!str) return 0;
    if(sscanf(str,"%s at %s",what,who)!=2 && str!="laughter" &&
      str!="laughter at") return 0;
    if(what && what!="laughter") return 0;
    CHK_GHOST();
    CHK_LVL(UNCONTROLLABLE_LEVEL);
    CHK_SP(UNCONTROLLABLE_COST);
    if(!who && !TPATT) {
	ME("Cast Uncontrollable Laughter at whom?\n");
	return 1;
    }
    if(!who) target=TPATT;
    else target=HERE(who,ENV(TP));
    if(!target || !living(target)) {
	ME("Cast Uncontrollable Laughter at whom?\n");
	return 1;
    }
    if(target==TP) {
	ME("You do not want to do this!\n");
	return 1;
    }
    if(HERE("laugher",target)) {
	ME(target->QNAME+" is already dancing.\n");
	return 1;
    }
    if(!TPWIZ) TPRSP(-UNCONTROLLABLE_COST);
    time=TPCHR*3;
    ME("You tell "+target->QNAME+" a killer joke!\n");
     say(TPN+" tells "+target->QNAME+" a killer joke!\n", target);
    TELL(target, TPN+" tells you a killer joke. You bust a gut in laughter!\n");
    laugher=CLONE(OBJ+"laugher");
    transfer(laugher,target);
    laugher->start_laugher(time,target);
    return 1;
}
