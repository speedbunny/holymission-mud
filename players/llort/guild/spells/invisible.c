
/* ################################################################
   #								  #
   #    		Mage invisibility                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;

  spnr=MS->spellnr("invisible");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr)); 

  if (TP->query_invis()) {
    write("You refresh your spell of invisibility.\n");
    return 1;
  }

  OTHERS(({ TP }),TPN+" "+TP->query_mmsgout()+".\n");
  this_player()->set_invis(this_player()->query_level()-1);
  ME("You fade away.\n");
  SOUL->refresh_invis(SPCOST(spnr));

  return 1;
}
