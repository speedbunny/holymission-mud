
/* ################################################################
   #								  #
   #    		Mage go guild                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;

  if (E(TP)->has_drink(TP)) {
    write("You are not allowed to leave with drinks!\n");
    return 1;
  }

  spnr=MS->spellnr("goguild");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  SOUL->set_go_mark(E(TP));

  if(E(TP)->query_property("no_teleport")) {
    ME("The spell fizzles as you crash against an invisible " +
      "wall of force.\n");
    OTHERS(({ TP }),TPN+" seems to get a bit transparent, but suddenly "+
      TP->query_pronoun()+" becomes solid again.\n");
  } else TP->move_player("X#"+MS->query_chamber());
  return 1;
}
