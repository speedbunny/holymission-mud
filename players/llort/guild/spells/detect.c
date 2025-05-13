/* 250294: Portil: Fixed bug caused by invisible object with enable_commands()*/
/* ################################################################
   #								  #
   #    		Mage detect life                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr,i;
object ob;

  spnr=MS->spellnr("detect");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  ob=all_inventory(E(TP));
  OTHERS(({ TP }),TPN+" closes "+TPPOS+" eyes. You can almost feel something "+
    "touching your mind.\n");
  ME("There are following livings around:\n");
  ME("-----------------------------------\n");
  for(i=0;i<sizeof(ob);i++)
    if(living(ob[i])&&(!ob[i]->query_immortal())) {
      if(!ob[i]->query_invis())
	{ if(ob[i]->short())
	ME(ob[i]->short()+"\n");
	}
      else
      	ME("("+ob[i]->query_name()+")\n");
    }
  ME("-----------------------------------\n");
  return 1;
}

