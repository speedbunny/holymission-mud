
/* ################################################################
   #								  #
   #    		  Mage fireshield                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object med;

  spnr=MS->spellnr("fireshield");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  med=clone_object("players/llort/guild/obj/fireshield");
  med->start_shadow(pl,TPL*FIRESHIELD_TIME);
  OTHERS(({ TP }),TPN+" starts emmitting a golden aura.\n");
  return 1;
}
