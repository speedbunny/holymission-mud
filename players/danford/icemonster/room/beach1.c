#include "path.h"
inherit "room/room";

reset(arg) {

      if (!arg) {

       set_light(1);
       short_desc = "A very nice beach";
       long_desc = "You are standing on a very nice beach. There are beach \n"+
		   "huts in all directions. Further to the east you can see the sea. \n";
       dest_dir = ({
	 ROOM + "entr", "south",
	 ROOM + "beach2", "north",
	 ROOM + "hut1", "west",
         ROOM + "hut2", "east"
		  });

		}
}
