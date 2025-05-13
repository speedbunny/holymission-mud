#include "bard.h"
#define AUDIBLE_COST 15
#define AUDIBLE_LEVEL 5

int main(string str) {
   object att;

   if(!str) return 0;
   if(str!="glamer") return 0;
   att=TPATT;
   if(!att) {
      ME("You are not fighting anyone!\n");
      return 1;
   }
   CHK_GHOST();
   CHK_SP(AUDIBLE_COST);
   CHK_LVL(AUDIBLE_LEVEL);
   if(!TPWIZ) TPRSP(-AUDIBLE_COST);
   ME("You cast the spell, eminating a loud noise from across the room "+
	"that startles "+att->QNAME+"!\n");
   TP->attack();
   if(TPL>20 && RAN(TPD)>27) TP->attack();
   say("A loud noise comes from behind, startling you!\n");
   TELL(att,"You jump at a sharp noise behind you.\n");
   return 1;
}
