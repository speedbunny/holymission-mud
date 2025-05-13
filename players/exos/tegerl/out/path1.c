

/* Tegerl's first room, coded 4.3.1995 */
/* rooms/out/path1 */
/* Exos - 04/29/97 Replace_program() */


inherit "room/room";
void reset(int arg) 
{
    if (!arg) {
	set_light(1);
	short_desc="A dim forest";

	long_desc=
	"You entered a dim large forest. " +
	"A narrow path meanders through it. " +
	"As you look into the depths of the forest you decide to follow the path " +
	"and don't dare to leave it. You can see that the path is used frequently " +
	"as there are footprints and trails of carriages. " +
	"Maybe you will meet some people living nearby.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/path2", "north",
	  "players/kelly/rooms/vill/road4","south",

	});

	items=({
	  "forest","The forest is very dark, you wonder what creatures could live in it. You decide to stay away",
	  "path","The ground is muddy and you can see that it has been used lately",
	  "footprints","Yes, footprints, and they are human",
	  "trails","As you look at the trails you think that maybe a carriage used this path",
	  "trail","As you look at the trail you think that maybe a carriage used this path",
	});


	smell = "The air is damp and you can smell rotten trees.";

    }
    ::reset(arg);
    replace_program("room/room");
}
