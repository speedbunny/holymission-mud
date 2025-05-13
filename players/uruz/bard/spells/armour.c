#include "bard.h"
#define ARMOUR_COST TPMSP
#define ARMOUR_LEVEL 12

int main(string str) {
    object ithan, dummy;
    int ac, time;

    if(!str) return 0;
    if(str!="of ithan") return 0;
    dummy=HERE("armour_of_ithan",TP);
    if(dummy) {
	ME("You are already protected!\n");
	return 1;
    }
    CHK_GHOST();
    CHK_ATT();
    CHK_SP(ARMOUR_COST);
    CHK_LVL(ARMOUR_LEVEL);
    if(!TPWIZ) TPRSP(-ARMOUR_COST);
    ME("Your entire body is surrounded by a blue glow, as you summon "+
	"Ithan's magical armour!\n");
    say(TPN+" is surrounded by a glowing blue aura.\n");
    ithan=CLONE(OBJ+"ithan");
    MOVE(ithan,TP);
    ac=(TPL/5)+(TPI/10);
    time=(((TPI+TPW)*25)+(TPL*50)+(TPLL*25));
    if(TPWIZ) ME("TIMER: "+time+" seconds.\n");
    if(ac>10) ac=10;
    ithan->set_ac(ac);
    ithan->set_weight(0);
    ithan->set_timer(time);
    command("wear armour_of_ithan",TP);
    return 1;
}
