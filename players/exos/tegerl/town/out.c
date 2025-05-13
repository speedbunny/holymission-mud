

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/out */


inherit "room/room";
void reset(int arg) 
{
    if (!arg);
    {
	clone_list=({1,1,"woman","players/tegerl/jabberwocky/monsters/ow",0});

	set_light(1);
	short_desc="A lost place in town";

	long_desc=
	"You have found a small place. Nothing else seems to be here. " +
	"All doors are closed and one road looks like the other. " +
	"Maybe you lost your way.\n";

	dest_dir=({

	  "players/tegerl/jabberwocky/rooms/town/maze1", "east", 
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
