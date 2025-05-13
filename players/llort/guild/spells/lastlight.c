
/* ################################################################
   #								  #
   #   		      Mage lasting light spell                    #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object ob;

  if(present("globe",TP)) {
    ME("There is already such a spell active.\n");
    return 1;
  }

  spnr=MS->spellnr("lastlight");
  CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));  

  ob=clone_object("/players/llort/guild/obj/globe");
  ob->set_name("globe");
  ob->set_short("globe of light");
  ob->set_long("A Globe emitting warm, bright light.\n");
  ob->set_weight(0);
  ob->set_llevel(3);
  move_object(ob,TP);
  OTHERS(({ TP }),"A globe of light appears in "+TPN+"'s hand.\n");
  ME("A globe of light appears in your hand.\n");
  
  ob->set_time(TIME_LLIGHT);
  if(ob->light(3)>0) {
    SAY("You can see again.\n");
  }
  return 1;
}
