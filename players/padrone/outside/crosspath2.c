/* Crosspath2 */
/* Recode - Exos 961028 */

inherit "room/room";

void reset(int arg) {
    if(!arg) {
	set_light(1);
	short_desc="A small path";
	long_desc=
	"You are on a small path winding through the bushes.\n";
	dest_dir=({
	  "/players/padrone/outside/finish_quest", "east",
	  "/players/padrone/outside/crossing", "west",
	});
    }
    ::reset();
    replace_program("room/room");
}
