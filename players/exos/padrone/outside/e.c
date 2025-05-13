/* e.c */
/* Recode - Exos 961028 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/outside/ne", "north",
	  "players/padrone/outside/se", "south",
	});
	short_desc = "East of Padrone's Castle",
	long_desc =
	"This is a small path that goes all the way around Padrone's Castle.\n" +
	"The eastern wall of the castle looms above you in its stony greyness.\n" +
	"To the east, there is nothing but the impenetrable trees of the deep\n" +
	"and dark forest.\n";
	clone_list=({
	  1, 1, "badger", "/players/padrone/monsters/badger", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
