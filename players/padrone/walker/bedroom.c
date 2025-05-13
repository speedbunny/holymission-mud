/* bedroom.c */
/* Recode - Exos 961023 */

inherit "/room/room";
#include "walker.h"

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/upper_hall", "west", });
	short_desc = "In a bedroom";
	long_desc =
	"This is a large, comfortable bedroom. The bed would have\n" +
	"looked nice, if it hadn't been for all the blood.\n";
	clone_list=({
	  1, 1, "pirate", "/players/padrone/monsters/lazy_pirate", 0,
	  -1, 1, "sword", "/players/padrone/obj/lsword", 0,
	  -1, 1, "shield", "/players/padrone/obj/shield", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
