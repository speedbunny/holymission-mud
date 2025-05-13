/* beach/path6 */

#include "path.h"
inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A path in a very nice beach-village.";
      long_desc =
"You are walking on a small path in east-west direction in the beach-village.\n"+
"You can see a crossing to the east. This path leads west to a big hut.\n";
      dest_dir = ({
	ROOM+"entr", "east",
        ROOM+"path7", "west"
		 });
		}
}
