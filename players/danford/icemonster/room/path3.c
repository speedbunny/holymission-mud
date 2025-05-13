#include "path.h"
inherit "room/room";



void reset(int arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A path in a very nice beach-village.";
      long_desc =
"You are standing on a small path in a beach-village.\n"+
"There are many footprints along this path in the pure white beach sand."+
" Small beach plants and foliage line either side of the path. There are"+
" beach huts to your north and south.\n";
      dest_dir = ({
	ROOM+"beach3", "west",
        ROOM+"path4", "east",
        ROOM+"hut6", "south",
        ROOM+"shop", "north"
		 });
 	items=({"hut","A small beach hut use to escape the oppressive sun of the beach",
	"huts","Small beach huts use to escape the oppressive sun of the beach",
        "plant","Scrubby looking plants typically found in and around the shore",
        "plants","Scrubby looking plants typically found in and around the shore",
        "foliage","Scrubby looking plants typically found in and around the shore",
 	 });

		}
}
