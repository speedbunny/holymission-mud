/* SE */
/* Recode - Exos 961028 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/outside/e", "north",
	  "players/padrone/outside/back_yard", "west",
	});
	short_desc = "Southeast of Padrone's Castle";
	long_desc =
	"This is a small path that goes all the way around Padrone's Castle.\n" +
	"You are at the southeast corner of the castle, and you are looking up\n" +
	"at the main tower of the castle - the big tower where Padrone himself\n" +
	"lives, and where he has his workroom and his laboratory.\n" +
	"The path continues north beneath the eastern wall of the castle,\n" +
	"and the back yard opens up to the west. to the east and to the\n" +
	"south you see nothing but the dark twisted trees of the\n" +
	"impenetrable forest.\n";
    }
    ::reset(flag);
    replace_program("room/room");
}
