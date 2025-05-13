
/* ################################################################
   #								  #
   #    		  Mage meditate                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,tim,meditate;
object med;

  if(!arg) {
    ME("How long ?\n");
    return 1;
  } 
  
  spnr=MS->spellnr("meditate");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  sscanf(arg,"%d",tim);
  meditate=MED_TIME;
  if(meditate<=0) {
    ME("You are not able to concentrate that hard.\n");
    return 1;
  }
  move_object(med=clone_object("players/llort/guild/obj/meditator"),TP);
  med->set_dur(meditate,SOUL);
  OTHERS(({ TP }),TPN+" sits down in the lotus-position.\n");
  ME("You sit down in the lotus-position.\n");
  return 1;
}
