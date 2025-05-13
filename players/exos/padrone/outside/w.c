/* W */
/* Recode - Exos 961028 */

inherit "room/room";

void reset(int arg) {
    if(!arg) {
	set_light(1);
	short_desc="West of Padrone's Castle";
	long_desc="This is a small path that goes all the way around Padrone's castle.\n"+
	"The western wall of the castle looms above you in its stony greyness.\n" +
	"To the west, there is nothing but the impenetrable trees of the deep\n" +
	"and dark forest.\n";
	dest_dir=({
	  "players/padrone/outside/nw", "north",
	  "players/padrone/outside/sw", "south",
	});
	clone_list=({
	  1, 1, "bird", "players/padrone/monsters/bird", 0,
	});
    }
    ::reset(arg);
    replace_program("room/room");
}
