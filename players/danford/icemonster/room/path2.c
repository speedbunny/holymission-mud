/* beach/path2 */

#include "path.h"
inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A path in a very nice beach-village.";
      long_desc =
"You are walking on a small path in east-west direction in the beach-village.\n"+
"You can see a crossing further east of you and an inviting hut to the south.\n"+
"On a huge sign you read: Randyandy's Beach Pizzeria & Pub.\n";
      dest_dir = ({
	ROOM+"path1", "east",
        ROOM+"castlepath3", "west",
        ROOM+"pub", "south"
		 });
		}
}
