#include "bard.h"
#define CONFUSION_COST 65
#define CONFUSION_LEVEL 18

int main(string str) {
    object target, confuser;
    string who;
    int time;

    if(!str && !TPATT) {
	ME("Cast Confusion at whom?\n");
	return 1;
    }
    CHK_GHOST();
    CHK_SP(CONFUSION_COST);
    CHK_LVL(CONFUSION_LEVEL);
    sscanf(str,"at %s",who);
    if(!who) target=TPATT;
    else target=HERE(who,ENV(TP));
    if(!target || !living(target)) {
	ME("Cast Confusion at whom?\n");
	return 1;
    }
    if(target==TP) {
	ME("You do not want to confuse yourself!\n");
	return 1;
    }
    if(HERE("confuser",target)) {
	ME(target->QNAME+" is already confused.\n");
	return 1;
    }
    if(!TPWIZ) TPRSP(-CONFUSION_LEVEL);
    time=TPCHR*3;
    ME("You strum an utterly confusing tune.\n");
    say(TPN+" strums a strange tune.\n",target);
    TELL(target,TPN+" strums a strange and confusing tune.\n");
    confuser=CLONE(OBJ+"confuser");
    transfer(confuser,target);
    confuser->start_confuser(time,target);
    return 1;
}
