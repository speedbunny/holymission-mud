/* nw.c */
/* Recode - Exos 961028 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1); 
	dest_dir = ({
	  "players/padrone/outside/w", "south",
	  "players/padrone/outside/front_yard", "east",
	  "players/padrone/outside/nice_place", "west",
	});
	short_desc = "Northwest of Padrone's Castle";
	long_desc =
	"This is a small path that goes all the way around Padrone's Castle.\n" +
	"You are at the northwest corner of the castle, and one of the castle's\n" +
	"grey stone towers rises high above you.\n" +
	"The view is probably very good from the top of that tower...\n" +
	"All around you you can see the dark trees that form the deep forest.\n" +
	"From here the path continues south along the western wall, but another\n" +
	"path forks off leading west to what might be a clearing of some sort.\n" +
	"To the east you can see the front yard of the castle, and from there\n" +
	"you can enter the castle through the main gate.\n";
    }
    ::reset(flag);
    replace_program("room/room");
}
