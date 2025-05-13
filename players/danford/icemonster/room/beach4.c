#include "path.h"

inherit "room/room";

object sign;

reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A very nice beach";
      long_desc =
"You are walking on a very nice beach. You can feel the warmth of the white\n"+
"sand under your feet. To the south you can see a small village made out\n"+
"of beach huts. You suddenly realize what the secret of this wonderful place\n"+
"is: It's always Saturday afternoon! A really nice place to live. To the north\n"+
"the path ends abruptly at a huge cliff.\n";
      dest_dir = ({
	"players/randyandy/beach3", "south"
		 });
		}
	if (!sign) {
	   sign = clone_object(OBJ+"city_sign");
	   move_object(sign, this_object());
	   }
}

