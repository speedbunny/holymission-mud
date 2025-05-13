#include "bard.h"
#define ENCHANTED_COST 75
#define ENCHANTED_LEVEL 15

int main(string str) {
    object weapon, shad;
    string what, sword;
    int strength, wc, timer;

    if(!str) return 0;
    if(sscanf(str,"%s at %s",what,sword)!=2 &&
      str!="weapon" && str!="weapon at") return 0;
    if(what && what!="weapon") return 0;
    if(!sword) {
	ME("Enchant which weapon?\n");
	return 1;
    }
    CHK_GHOST();
    CHK_LVL(ENCHANTED_LEVEL);
    CHK_SP(ENCHANTED_COST);
    weapon=HERE(sword,TP);
    if(!weapon || !weapon->QWEP) {
	ME("Enchant which weapon?\n");
	return 1;
    }
    wc=weapon->WC;
    if(wc>=20 || weapon->enchant_shad()) {
	ME("That weapon is already enchanted!\n");
	return 1;
    }
    if(!TPWIZ) TPRSP(-ENCHANTED_COST);
    strength=TPL/5;
    timer=TPL*5;
    if(TPL>=29 && TPLL>=1) strength=10;
    if(wc+strength>20) strength=(20-wc);
    shad=CLONE(OBJ+"enchant_shad");
    if(TPWIZ) ME("WIZ INFO: Class: "+(strength+wc)+" Timer: "+timer+".\n");
    shad->start_shadow(weapon,timer,strength);
    return 1;
}
