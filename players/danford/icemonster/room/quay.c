/* beach/quay */

#include "path.h"
inherit "room/room";



reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "The small quay of Surf City.";
      long_desc =
"This is the small quay of Surf City. The Village can be seen to the north.\n"+
"You are surrounded by water. It smells like rotten fish.\n";
      dest_dir = ({
        ROOM+"entr", "north"
		 });
		}
}
