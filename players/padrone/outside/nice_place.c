/* nice_place.c */
/* Recode - Exos 961028 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/outside/small_lake", "north",
	  "players/padrone/outside/nw", "east",
	});
	short_desc = "On a nice place";
	long_desc =
	"This is really a nice place. You are in a small clearing\n" +
	"with soft grass just at the shore of a small, beautiful\n" +
	"lake. Tall trees surround the clearing, and to the east\n" +
	"a small path leads to Padrone's Castle. You feel at peace\n" +
	"here.\n";
	clone_list=({
	  1, 1, "butterfly", "/players/padrone/monsters/butterfly", 0, 
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
