
/* ################################################################
   #								  #
   #    		Mage visible again                        #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#include "../tune.h"

doit(arg,pl) {
  if (TP->query_ghost()) {
    ME("You try to show yourself to mortal men.\n");
    return 1;
  }
  SOUL->end_invis();
  if (!TP->query_invis()) {
    write("You are not invisible !\n");
    return 1;
  }
  TP->set_vis();
  move_object(TP,E(TP));
  OTHERS(({ TP }),TPN+" "+TP->query_mmsgin()+".\n");  
  ME("You shimmer into a solid form.\n");
  return 1;
}
