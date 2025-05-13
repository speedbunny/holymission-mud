#include "bard.h"
#define PYROTECHNICS_COST 75
#define PYROTECHNICS_LEVEL 10

int main() {
   object *all;
   int i, j, damage;
   
   CHK_GHOST();
   CHK_SP(PYROTECHNICS_LEVEL);
   CHK_LVL(PYROTECHNICS_LEVEL);
   if(!TPWIZ) TPRSP(-PYROTECHNICS_COST);
   ME("You release a flury of pyrotechnic explosions from your hands.\n");
   say("You are caught in a shower of pyrotechnic explosions from "+TPRN+"'s"+
	" hands!\n");
   damage=(TPL*2+RAN(10)+1+TPLL/10);
   if(damage>75) damage=75;
   if(TPWIZ)
      ME("WIZ INFO: Damage "+damage+".\n");
   all=INVALL(ENV(TP));
   j=sizeof(all);
   TP->XP(j*5);
   for(i=0;i<j;i++) {
if(living(all[i]) && all[i]->QNPC) {
         all[i]->attacked_by(TP);
         all[i]->hit_player(damage);
      }
   }
   return 1;
}
