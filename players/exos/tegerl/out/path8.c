

/* Coded by Tegerl, 8.3.1995 */
/* rooms/out/path8 */
/* Exos - 04/29/97 Replace_program() */


inherit "room/room";
void reset(int arg) 
{
    if (!arg) {
	set_light(1);
	short_desc="A dim forest";

	long_desc=
	"You hope that this forest will soon end. " +
	"You are getting paranoid walking this path through " +
	"this weird forest.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/path7", "southwest",
	  "players/tegerl/jabberwocky/rooms/out/path9", "northeast",
	});

	items=({
	  "forest","The forest is very dark, you wonder what creatures could live in it. You decide to stay away",
	  "path","The ground is muddy and you can see that it has been used lately",
	  "footprints","Yes, footprints, and they are human",
	  "trails","As you look at tho trails you think that maybe a carriage used this path",
	});

	smell = "The air is damp and you can smell rotten trees.";

    }
    ::reset(arg);
    replace_program("room/room");
}
