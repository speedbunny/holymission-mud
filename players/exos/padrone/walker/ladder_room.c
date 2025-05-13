/* ladder room */
/* Recode - Exos 961025 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/main_hall", "south",
	  "players/padrone/walker/rope_ladder", "down", });
	short_desc = "A room on the groundfloor of the walking castle";
	long_desc =
	"This is a small room on the groundfloor of the walking castle.\n" +
	"This used to be a servant's room, but now the furniture is\n" +
	"broken and there is blood on the floor. A rope ladder leads\n" +
	"down through a hole in the floor. From the south you can smell\n" +
	"the bad smelling tabacoo the pirates use to smoke.\n"; 
    }
    ::reset(flag);
    replace_program("room/room");
}
