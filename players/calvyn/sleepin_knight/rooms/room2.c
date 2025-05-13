#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room2. (nw,d)";

	long_desc=
	
	"You have finally found the source of the smell. On top of this large\n"
"object you find 5 stinky toes dancing around. Across the way to the west you\n"
"see 5 more toes, but the gap between you and the other side is too far\n"
"to jump across. There is also a rope here, creating a downwards exit.\n"
"To the north the terrain gets bumpy.\n";

	dest_dir=({
	"/players/calvyn/body/room3.c", "northwest"
	"/players/calvyn/body/room1.c", "down"
	});

	items=({ 
	"gap","Quite a large gap, you'll never make it if you jump.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "'PHEW!' Smells like a gym locker room!";
    }
}

init()
{
    ::init();
}
