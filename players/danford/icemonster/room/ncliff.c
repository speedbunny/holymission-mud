/* standing on a cliff. */

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
      	"sea", "As you look down the cliff you can only see water",
      });
      dest_dir = ({
      	ROOM+"path4", "west",
      	ROOM+"cliff2", "south"
      });
     }
}

