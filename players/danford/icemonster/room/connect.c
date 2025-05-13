/* beach/connect */

#include "path.h"
inherit "room/room";

object sign;

init() {
	::init();
	add_action("west", "west");
}

reset(arg) {

     if (!arg) {

      set_light(1);
      short_desc = "A small sandy path";
      long_desc =
"You are walking on a small sandy path in east-west direction.\n"+
"You can see many beach huts to the east. There seems to be a small village.\n"+
"Further to the east lies the sea. You feel a fresh breeze from there.\n";
      dest_dir = ({
	"players/talagan/room/room3", "west",
        ROOM+"castlepath3", "east"
		 });
		}
	if (!sign) {
		sign = clone_object(OBJ+"city_sign");
		move_object(sign, this_object());
	}	
}

west() {
	this_player()->move_player("west#/players/talagan/room/room3");
/*	log_file("randyandy.city", ctime(time())+" "+this_player()->query_name()+" leaves Surf City to the west.\n"); */
	return 1;
}

	
