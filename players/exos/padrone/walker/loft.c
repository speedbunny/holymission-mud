/* loft */
/* Recode - Exos 961026 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "/players/padrone/walker/upper_hall", "down",
	});
	short_desc = "The loft of the walking castle";
	long_desc =
	"This is a small loft, high up in the walking castle.\n";
	clone_list=({
	  1, 1, "pirate", "/players/padrone/monsters/greedy_pirate", 0,
	  -1, 1, "sword", "/players/padrone/obj/ssword", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
