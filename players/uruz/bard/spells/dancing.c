#include "bard.h"
#define DANCING_COST 5
#define DANCING_LEVEL 1

int main(string str) {
object globe;

    if(str) return 0;
    CHK_GHOST();
    CHK_ATT();
    CHK_LVL(DANCING_LEVEL);
    CHK_SP(DANCING_COST);
    if(!TPWIZ) TPRSP(-DANCING_COST);
    ME("The twinkling of a million points of light brighten the room.\n");
    say("The twinkling of a million points of light brighten the room.\n");
globe=CLONE(OBJ+"globe");
    if(ENV(TP)->set_light(1)==1) {
	ME("You can see again.\n");
	say("You can see again.\n");
    }
    return 1;
}
