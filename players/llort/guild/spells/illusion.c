
/* ################################################################
   #								  #
   #    		Mage illusion                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

object pl;

doit(arg,xx) {
int spnr;
  
  pl=xx;
  if(!arg) {
    ME("What does it look like ?\n");
    return 1;
  }
  
  spnr=MS->spellnr("illusion");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  ME("Enter a short description of your illusion:\n>>");
  SOUL->start_illusion(arg,ILLU_TIME);
  
  return 1;
} 
