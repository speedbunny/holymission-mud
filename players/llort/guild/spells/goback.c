
/* ################################################################
   #								  #
   #    		    Mage goback                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;

  spnr=MS->spellnr("goback");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));
  if(E(TP)->query_property("no_teleport")) {
    ME("The spell fizzles as you crash against an invisible " +
      "wall of force.\n");
    OTHERS(({ TP }),TPN+" seems to get a bit transparent, but suddenly "+
      TP->query_pronoun()+" becomes solid again.\n");
    return 1;
  }
  if (SOUL->query_go_mark()) {
    if(SOUL->query_go_mark()->query_property("no_teleport")) {
      ME("The spell fizzles as you crash against an invisible " +
        "wall of force.\n");
      OTHERS(({ TP }),TPN+" seems to get a bit transparet, but suddenly "+
        TP->query_pronoun()+" becomes solid again.\n");
      return 1;
    } else TP->move_player("X",SOUL->query_go_mark());
  } else TP->move_player("X#"+MS->query_chamber()); /* object was destructed */

  ME("You returned.\n");
  return 1;
}
