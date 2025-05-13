/* Kitchen */
/* Recode - Exos 961026 */
inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/banquet_hall", "south",
	});
	short_desc = "In the kitchen of the walking castle";
	long_desc =
	"This is the kitchen of the walking castle.\n" +
	"The pirates had a party yesterday, and if you hadn't seen it\n" +
	"for yourself you wouldn't have believed that it is possible\n" +
	"for a kitchen to be so filthy.\n";
	clone_list=({
	  1, 1, "pirate1", "/players/padrone/monsters/hungry_pirate", 0,
	  2, 1, "pirate2", "/players/padrone/monsters/perverted_pirate", 0,
	  -1, 1, "knife", "/players/padrone/obj/knife", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}
