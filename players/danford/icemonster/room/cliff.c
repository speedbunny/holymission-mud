/* looking from the cliff ... */

#include "path.h"
inherit "room/room";

reset(arg) {
	
     if (!arg) {
     	
      set_light(1);
      short_desc = "Top of a cliff.";
      long_desc =
"You are standing on top of a cliff. Looking down you can see the sea. \n"+
"The cliff is very deep, so you decide better not to jump down.\n";
      items = ({
      	"sea", "You look down the cliff and can see the sea stretching far beyond the \n"+
      	       "horizon",
      });
      dest_dir = ({
      	ROOM+"path5", "west",
      	ROOM+"cliff1","north"
      });
     }
}

