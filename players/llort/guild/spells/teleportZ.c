
/* ################################################################
   #								  #
   #    		    Mage goback                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;

  spnr=MS->spellnr("teleport");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));
  
  if (E(TP)->query_property("no_teleport")) { // moonchild 190893
    ME("The spell fizzles as you crash against an invisible wall of force.\n");
    OTHERS(({ TP }),TPN+" seems to get a bit transparent, but suddenly "+
        TP->query_pronoun()+" becomes solid again.\n");
  } else if (SOUL->query_tp_mark()) {
    if(SOUL->query_tp_mark()->query_property("no_teleport")) {
      ME("The spell fizzles as you crash against an invisible " +
        "wall of force.\n");
      OTHERS(({ TP }),TPN+" seems to get a bit transparent, but suddenly "+
        TP->query_pronoun()+" becomes solid again.\n");
      return 1;
    } else TP->move_player("X",SOUL->query_tp_mark());
  } else ME("You are not sure where to teleport to!?!\n");

  return 1;
}
