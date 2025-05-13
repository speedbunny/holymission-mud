
/* ################################################################
   #								  #
   #    		Mage regeneration staff                   #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
int spnr;
object st;

  spnr=MS->spellnr("staff");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(TP->query_max_sp());
  ADDSP(-TP->query_max_sp());
  CHK_FIZ(SPLVL(spnr));
  if(present("llort_guild_staff", TP)) {
    write("You already have a staff.\n");
    return 1;
  }
  if(transfer(st=clone_object("/players/llort/guild/obj/staff"),TP)) {
    write("You are carrying too much, and drop the staff. It starts to fade.\n");
    destruct(st);
    return 1;
  } /* Moonchild - change move_object to transfer and check for weight */
  st->set_class(STAFF_WC);
  OTHERS(({ TP }),TPN+" summons a staff out of nowhere.\n");
  ME("You summon a staff out of nowhere.\n");
  return 1;
}
