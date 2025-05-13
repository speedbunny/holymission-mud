#include "path.h"

inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A very nice beach";
      long_desc =
"This is a very nice beach. You feel very happy as you walk through the\n"+
"white sand. The sea lies further to the east. There are some huts here.\n"+
"Surf City must be a really nice place as you soon realize.\n";
      dest_dir = ({
	ROOM+"beach1", "south",
        ROOM+"hut3", "west",
        ROOM+"hut4", "east",
        ROOM+"beach3", "north",
		 });
		}
}
