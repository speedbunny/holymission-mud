
/* ################################################################
   #								  #
   #    		  Mage gate spell                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object dest,gate;

  if(!arg) {
    ME("Open a gate to whom ?\n");
    return 1;
  } 
  
  spnr=MS->spellnr("gate");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  dest=find_living(arg);
  if(!dest) {
    ME("You are not able to find "+arg+".\n");
    return 1;
  }
  if(!dest->query_player()) {
    ME("You can only open a gate to a player.\n");
    return 1;
  }
  if(dest->query_immortal()) {
    ME("You can not open a gate to a wizard.\n");
    return 1;
  }
  if(E(dest)->query_property("no_teleport") ||
     E(TP)->query_property("no_teleport")) {
    write("A strange magical force seems to block the spell.\n");
    return 1;
  }

  move_object(gate=clone_object("players/llort/guild/obj/gate"),E(dest));
  gate->set_gate(TP);
  OTHERS(({ TP }),TPN+" speaks some magic words.\n");
  ME("You open a gate to "+dest->query_name()+".\n");
  return 1;
}
