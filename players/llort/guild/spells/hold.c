
/* ################################################################
   #								  #
   #    		Mage hold spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,tim;
object ob;

  if(!arg) {
    ob=TP->query_attack();
    if(ob && present(ob, E(TP)))
      arg=ob->query_name();
    else if(ob) {
      ME("Holding "+ob->query_name()+
         " is not possible without line of sight.\n");
      return 1;
    }
    else {
      ME("Hold whom ?\n");
      return 1;
    }
  } else ob=present(arg,E(TP));

  if((!ob) || (!living(ob)) || (ob->query_immortal())) {
    ME("You just can't hold "+arg+".\n");
    return 1;
  }

  spnr=MS->spellnr("hold");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  if(ob->query_npc()) tim=HOLD_NPC;
  else tim=HOLD_PLAYER;
  tim=2*random(tim);
  if(tim>0) ob->hold(SOUL,tim);
  if(TP->query_immortal()) write("Time (Wizinfo): "+tim+"\n");
  ME("You hold "+ob->query_name()+".\n");
  OTHERS(({ TP,ob }),TPN+" holds "+ob->query_name()+".\n");
  YOU(ob,TPN+" holds you.\n");
  return 1;
}
