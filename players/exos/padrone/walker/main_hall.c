/* Main Hall */
/* Recode - Exos 961026 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	short_desc = "In the main hall of the walking castle";
	dest_dir = ({
	  "players/padrone/walker/ladder_room", "north",
	  "players/padrone/walker/castle_yard", "south",
	  "players/padrone/walker/upper_hall", "up",
	  "players/padrone/walker/banquet_hall", "east",
	});
	long_desc =
	"You are in the main hall of the walking castle.\n" +
	"This used to be a luxurious and impressingly decorated place,\n" +
	"but since a band of pirates took over this castle. The\n" +
	"expensive furniture has been broken, the thick carpets\n" +
	"have been stained with blood, and the antique chandeliers\n" +
	"have been smashed to pieces.\n";
	clone_list=({
	  1, 1, "pirate", "/players/padrone/monsters/evil_pirate", 0,
	  -1, 1, "cutlass", "/players/padrone/obj/rcutlass", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
