
/* ################################################################
   #								  #
   #    		 Mage memorize site                       #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;

  if(!arg || lower_case(arg)!="site") return 0;
  spnr=MS->spellnr("memorize");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  if(environment(TP)->query_property("no_teleport")) {
      ME("The area shifts before your eyes, it seems you can't memorize it.\n");
      return 1;
    } else SOUL->set_tp_mark(environment(TP));
  ME("After concentrating for a while you have memorized this area.\n");
  OTHERS(({ TP }),TPN+" looks carefully around the area.\n");
  return 1;
}
