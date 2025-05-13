/* shop.c */
/* Recode - Exos 961026 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/castle_yard", "east",});
	short_desc = "The shop of the walking castle";
	long_desc =
	"You are in what used to be the local shop. Here you\n" +
	"could buy and sell items of different kinds, but the\n" +
	"pirates have of course stolen everything they could carry,\n" +
	"and smashed the rest to small pieces.\n";
	clone_list=({
	  1, 1, "pirate1", "/players/padrone/monsters/disgusting_pirate", 0,
	  2, 1, "pirate2", "/players/padrone/monsters/rude_pirate", 0,
	  -1, 1, "knife", "/players/padrone/obj/knife", 0,
	  -2, 1, "axe", "/players/padrone/obj/handaxe", 0,
	});
    }
    ::reset(flag);
    replace_program("room/room");
}

