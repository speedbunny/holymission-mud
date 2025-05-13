/* banquet_hall.c */
/* Recode - Exos 961023 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/kitchen", "north",
	  "players/padrone/walker/main_hall", "west",
	});
	short_desc = "The banquet hall of the walking castle";
	long_desc =
	"This is the banquet hall of the walking castle.\n" +
	"It looks like the pirates had a party here yesterday...\n" +
	"Everything has been smashed to pieces, and there is blood\n" +
	"on the walls and huge puddles of vomit on the floor.\n";
    }
    ::reset(flag);
    replace_program("room/room");
}

