/* SW */
/* Recode - Exos 961028 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/outside/w", "north",
	  "players/padrone/outside/back_yard", "east",
	});
	short_desc = "Southwest of Padrone's Castle";
	long_desc =
	"This is a small path that goes all the way around Padrone's Castle.\n" +
	"You are at the southwest corner of the castle, and the path leads \n" +
	"north beneath the western wall of the castle. The back yard opens up\n" +
	"to the east, but to the west and to the south you see nothing \n" +
	"but the dark and twisted trees of the impenetrable forest.\n";
    }
    ::reset(flag);
    replace_program("room/room");
}
