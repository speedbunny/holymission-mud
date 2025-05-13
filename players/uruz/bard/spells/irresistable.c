#include "bard.h"
#define IRRESISTABLE_COST 50
#define IRRESISTABLE_LEVEL 25

int main(string str) {
    object target, dancer;
    string what, who;
    int time;

    if(!str) return 0;
    if(sscanf(str,"%s at %s",what,who)!=2 && str!="dance" &&
      str!="dance at") return 0;
    if(what && what!="dance") return 0;
    CHK_GHOST();
    CHK_LVL(IRRESISTABLE_LEVEL);
    CHK_SP(IRRESISTABLE_COST);
    if(!who && !TPATT) {
	ME("Cast Irresistable Dance at whom?\n");
	return 1;
    }
    if(!who) target=TPATT;
    else target=HERE(who,ENV(TP));
    if(!target || !living(target)) {
	ME("Cast Irresistable Dance at whom?\n");
	return 1;
    }
    if(target==TP) {
	ME("You cannot cast Irresistable Dance at yourself!\n");
	return 1;
    }
    if(HERE("dancer",target)) {
	ME(target->QNAME+" is already dancing.\n");
	return 1;
    }
    if(!TPWIZ) TPRSP(-IRRESISTABLE_COST);
    time=TPCHR*3;
    ME("You strum an irresistable tune, and "+target->QNAME+" starts to dance.\n");
    say(TPN+" strums an irresistable tune, and "+target->QNAME+
      " begins to dance insanely around the room!\n");
    TELL(target, TPN+" strums a tune, and you suddenly quench your "+
	"enormous desire to dance!\n");
    dancer=CLONE(OBJ+"dancer");
    transfer(dancer,target);
    dancer->start_dancer(time,target);
    return 1;
}
