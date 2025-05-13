/* Coded by Tegerl, 4.3.1995 */
/* rooms/out/path3 */
/* Exos - 04/29/97 Replace_program() */

inherit "room/room";
void reset(int arg)
{
    if (!arg) {
	set_light(1);
	short_desc="A dim path in forest";

	long_desc=
	"You are still on a dim path in forest. " +
	"To the south the forest lightens. Maybe this is a chance to get out of here. " +
	"It seems as if there would be a small cottage in the southwest, but you are not sure. " +
	"There are many footprints and trails.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/path4", "north",
	  "players/tegerl/jabberwocky/rooms/out/clear", "south",
	});

	items=({
	  "forest","The forest is not that dark here, but you decide to stay away anyway",
	  "path","The ground is muddy and you can see that it has been used lately",
	  "footprints","Yes, footprints, and they are human",
	  "trails","As you look at the trails you think that maybe a carriage used this path",
	  "trail","As you look at the trail you think that maybe a carriage used this path",
	});

	smell = "The air is a bit fresher here but you can still smell damp rotten trees.";

    }
    ::reset(arg);
    replace_program("room/room");
}
