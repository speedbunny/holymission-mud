
/* ################################################################
   #								  #
   #    		Mage knock door                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(str,pl) {
object door; 
int i,num_doors,spnr;
string dest;

  if(!str) return;

  if (str!="door" && sscanf(str,"%s door",dest)!=1) return;
  if (!(door=present(str,E(TP)))) return;

  spnr=MS->spellnr("Knock");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));  

  if (str=="door" && (num_doors=door->number_of_doors())!=1) {
    door->which_door();
    return 1;
  }

  if (!door->query_locked()) {
    ME("Your spell fizzles on the unlocked door.\n");
    OTHERS(({ TP }),TPN+" tries to cast a spell at the "+str+" but fails.\n");
    return 1;
  }

  i=KNOCK_CHANCE;
  if (random(101)>=i) {
    ME("Your spell fizzles.\n");
    OTHERS(({ TP }),TPN+" tries to cast a spell at the "+str+" but fails.\n");
    return 1;
  }

  ME("The lock glows bright for a moment.\n");
  OTHERS(({ TP }),"The lock "+str+" glows bright for a moment.\n");

  door->set_locked(0);
  door->query_partner_door()->set_locked(0);

  return 1;
}
