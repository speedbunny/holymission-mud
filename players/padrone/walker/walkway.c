/* walkway */
/* Recode - Exos 961025 */

inherit "/room/room";

void reset(int flag) {
    if(!flag) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/walker/upper_hall", "north",
	  "players/padrone/walker/bridge", "south",
	});
	short_desc = "On the walkway above the castle yard";
	long_desc =
	"You are standing on a walkway above the castle yard. To the\n" +
	"north you can enter the castle itself, and to the south you\n" +
	"see a strange room built on top of the gatehouse. The room\n" +
	"has many windows and you think it might be important.\n"; 
    }
    ::reset(flag);
    replace_program("room/room");
}
