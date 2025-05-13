/* Coded by Tegerl, 6.3.1995 */
/* rooms/out/path4 */
/* Exos - 04/29/97 Replace_program() and clone_list */

inherit "room/room";
void reset(int arg)
{
    if (!arg) {
	set_light(1);
	short_desc="A dim path in forest";

	long_desc=
	"You are still on a dim path in forest. " +
	"To path continues to the north and the south. But which way to go? " +
	"There are only a few footprints and you wonder why people don't travel " +
	"that much in this area.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/path3", "south",
	  "players/tegerl/jabberwocky/rooms/out/cross", "north",
	});

	items=({
	  "forest","The forest dark here and weird, so you decide to stay away",
	  "path","The ground is muddy and you can see that it is barely used",
	  "footprints","Yes, footprints, and they are human",

	});

	smell = "You can still smell damp rotten trees.";

	clone_list=({
	  1, 1, "fishfinger", "/players/tegerl/jabberwocky/monsters/ff", 0,
	});
    }
    ::reset(arg);
    replace_program("room/room");
}
