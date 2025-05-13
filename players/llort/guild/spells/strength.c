
/* ################################################################
   #								  #
   #    		  Mage stength                            #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object med,vic;

  spnr=MS->spellnr("strength");
  CHK_LIGHT(); CHK_GHOST();

  if(!arg) vic=TP;
  else
  {
     vic=present(arg,environment(TP));
     if(!vic)
     {
        write("On whom ?\n");
        return 1;
     };
  };

  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  med=clone_object("players/llort/guild/obj/strength");
  med->start_shadow(vic,TPL*STRENGTH_TIME);
  OTHERS(({ vic }),vic->query_name()+" looks stronger.\n");
  return 1;
}
