/* Matt 8-13-93: Changed to use filter_array() */


/* ################################################################
   #								  #
   #   			    Mage talk                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(str,pl) {
string msg,na;
object *u,hissoul;
int i,spnr;

  spnr=MS->spellnr("mage");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  return this_player()->guild_line(str);	/*161093 HERP*/
}
