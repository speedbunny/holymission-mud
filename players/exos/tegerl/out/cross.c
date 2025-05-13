/* Coded by Tegerl, 6.3.1995 */
/* rooms/out/cross */
/* Exos 04-29-97 Replace_program */

inherit "room/room";
void reset(int arg)
{
    if (!arg) {
	set_light(1);
	short_desc="A crossing in forest";

	long_desc=
	"Here in the middle of the forest the route to the north ends. " +
	"But another path leads in from the west to the northeast. " +
	"In the northeast the forest gets even darker. " +
	"In the west the forest gets lighter and even seems to end.\n"; 

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/path5", "west",
	  "players/tegerl/jabberwocky/rooms/out/path7", "northeast",
	  "players/tegerl/jabberwocky/rooms/out/path4", "south"
	});

	items=({
	  "forest","The forest dark here and weird, so you decide to stay away",
	  "path","The ground is muddy and you can see that it is barely used",
	  "footprints","Yes, footprints, and they are human",

	});

	smell = "You can still smell damp rotten trees.";

    }
    ::reset(arg);
    replace_program("room/room");
}
