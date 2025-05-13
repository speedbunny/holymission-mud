/* beach/path5 */

#include "path.h"
inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A path in a very nice beach-village.";
      long_desc =
"You are walking on a small path in east-west direction in the beach-village.\n"+
"You can see a crossing to the west. This path leads east to a cliff.\n";
      dest_dir = ({
	ROOM+"entr", "west",
        ROOM+"cliff", "east"
		 });
		}
}
