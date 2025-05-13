#include "path.h"

inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A very nice beach";
      long_desc =
"This is a very nice beach. The sun is shining and you are very happy.\n"+
"It's just great to be here. A path leads west from here and another one\n"+
"leads east to the sea. Further to the north you can see a huge cliff.\n";
      dest_dir = ({
	ROOM+"beach2", "south",
        ROOM+"beach4", "north",
        ROOM+"path1", "west",
        ROOM+"path3", "east"
		 });
		}
}
