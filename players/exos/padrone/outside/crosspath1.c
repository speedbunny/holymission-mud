/* Crosspath1 */
/* Recode - Exos 961028 */

inherit "room/room";

void reset(int arg) {
    if(!arg) {
	set_light(1);
	short_desc="A small path";
	long_desc=
	"You are on a small path winding through the bushes.\n";
	dest_dir=({
	  "/players/padrone/outside/north_shore", "west",
	  "/players/padrone/outside/crossing", "east",
	});
    }
    ::reset();
    replace_program("room/room");
}
