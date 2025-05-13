/* beach/path7 */

#include "path.h"
inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A path in a very nice beach-village.";
      long_desc =
"You are walking on a small path in east-west direction in the beach-village.\n"+
"You can see a crossing further to the east. There is a big hut to the west.\n";
      dest_dir = ({
	ROOM+"path6", "east",
        CAVE+"bighut", "west"
		 });
		}
}
