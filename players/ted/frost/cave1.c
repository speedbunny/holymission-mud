
inherit "room/room";

void reset(int arg)
{
    ::reset(arg);
    if (!arg) 
    {
	//    set_light(1);
	short_desc = "Dark Cave";
	long_desc =
	"You enter a dark cave. The floor and walls are covered with ice\n"+
	"and snow. Ice stalagmites and stalagtites jut from the floor and\n"+
	"hang from the ceiling. Your light causes rainbows of color to\n"+
	"spring forth, transforming the cave in a dazzle of color!\n";
	dest_dir = ({
	  "players/ted/frost/base", "south",
	  "players/ted/frost/cave2", "north"
	});
	items = ({
	  "ice","The ice is transformed into a rainbow of color!!",
	  "snow","The ice is transformed into a rainbow of color!!",
	  "stalagmites","Growths of ice that jut from the floor",
	  "stalagtites","Large icicles that hang from the ceiling"
	});
    }
}

