
/* ################################################################
   #								  #
   #    		Mage shield spell                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,ac;

  if(SOUL->armour_class()>STD_AC_OF_ROBE) {
    ME("There is already a shield spell active.\n");
    return 1;
  }

  spnr=MS->spellnr("shield");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr)); 
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  ac=SHIELD_AC;
  SOUL->set_ac(ac);
  if(SOUL->query_worn()) {
    this_player()->recalc_ac();
    OTHERS(({ TP }),TPN+"'s starts emitting a faint, blue aura.\n");
    ME("You start emitting a faint, blue aura.\n");
  }
  SOUL->shield_call_out(TIME_SHIELD);
  return 1;
}
