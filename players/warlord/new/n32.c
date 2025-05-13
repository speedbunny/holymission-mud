inherit "/players/warlord/NEWSTUFF/room";
reset(arg)
{
    if (arg)
	return;
    set_light(1);
    short_desc = "Winter forest\n";
    long_desc = "You feel the cold wind nipping at your skin. To the west is a large\n" +
	"ice barrier and to the east there are trees far to dense to pass\n" +
	"through.\n";
    dest_dir = ({
		    "players/warlord/new/n24", "north",
		    "players/warlord/new/n40", "south",
	});
    search = ({"top", "this is top",
	});
    return 1;
}
