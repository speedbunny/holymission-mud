/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/lake1 */
/* Exos - 04/29/97 Replace_program() */

inherit "room/room";
void reset(int arg)
{
    if (!arg) {
	set_light(1);
	short_desc="A lake";

	long_desc=
	"You are at the coast of a lake. The water is darkblue and you " +
	"feel save here. The lake continues to the south. A path follows " +
	"the coastline to the southwest and disappears in the forest to " +
	"the east.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/lake2", "southwest",
	  "players/tegerl/jabberwocky/rooms/out/path6", "east",
	});

	items=({
	  "path","The ground is muddy and you can see that it has been used lately",
	  "footprints","Yes, footprints, and they are human",
	  "trails","As you look at the trails you think that maybe a carriage used this path",
	  "lake","The water is darkblue and you can see fishes under the surface",
	});

	smell = "You smell water. The air is fresh and clear.";

    }
    ::reset(arg);
    replace_program("room/room");
}
