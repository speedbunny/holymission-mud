/* Lake_Bottom */
/* Recode - Exos 961028 */

inherit "players/cashimor/inherit/water";

void reset(int arg) {
    if(!arg) {
	short_desc="Bottom of small lake";
	long_desc="You are under the water. There is sunshine coming down from\n"
	+ "above. You notice a hole in the bottom of the lake.\n";
	set_light(1);
	dest_dir=({"players/padrone/outside/small_lake","up",
	  "players/padrone/outside/tunnel1","down"});
	floats="players/padrone/outside/tunnel1";
	damage=2;
	clone_list=({
	  1, 1, "fish", "/players/padrone/monsters/fish", 0,
	});
    }
    ::reset(arg);
    replace_program("players/cashimor/inherit/water");
}
