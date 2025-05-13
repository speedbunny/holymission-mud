/* standing on a cliff. */

#include "path.h"
inherit "room/room";

reset(arg) {
	
     if (!arg) {
     	
      set_light(1);
      short_desc = "A Path on the top of a cliff.";
      long_desc =
"You are walking a small path on top of a cliff. Looking down you can see the \n"+
"sea. The cliff is very deep, so you decide better not to jump down.\n";
      items = ({
      	"sea", "You look down the cliff and see water, nothing but water",
      });
      dest_dir = ({
      	ROOM+"cliff2", "north",
      	ROOM+"cliff", "south"
      });
     }
}

