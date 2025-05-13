/* beach/path1 */

#include "path.h"
inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A path in a very nice beach-village.";
      long_desc =
"You are walking on a small path in east-west direction in the beach-village.\n"+
"You can see a crossing east of you and a small hut to the north. The path\n"+
"continues to the west.\n";
      dest_dir = ({
	ROOM+"beach3", "east",
        ROOM+"path2", "west",
        ROOM+"hut5", "north"
		 });
		}
}
