
/* ################################################################
   #								  #
   #    	     Mage stop the light spells                   #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

doit(arg,pl) {
int spnr;
object ob;

  if(!(ob=present("globe",TP))) {
    write("There is no active light spell.\n");
    return 1;
  }

  spnr=MS->spellnr("stoplight");
  CHK_GHOST();

  ob->end_light();
  return 1;
}   
