

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/maze3 */
/* Exos - 05/01/97 replace_program() */


inherit "room/room";
void reset(int arg) 
{
    if (!arg) {
	set_light(1);
	short_desc="In a lonely part of town";

	long_desc=
	"This is a very lonely part of town. " +
	"All doors are closed and one road looks like the other. " +
	"Maybe you lost your way.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/town/maze2", "west",
	  "players/tegerl/jabberwocky/rooms/town/maze2", "north",
	  "players/tegerl/jabberwocky/rooms/town/street7", "east", 
	  "players/tegerl/jabberwocky/rooms/town/maze2", "south",
	});

	items=({
	  "wall","The wall is very old and needs to be repaired",
	  "doors","The doors are simple wooden doors, but they are all closed",
	});
	property = ({ "no_teleport" });
	smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";

    }
    ::reset(arg);
    replace_program("room/room");
}
