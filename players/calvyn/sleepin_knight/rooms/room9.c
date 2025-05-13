#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room9. (n,s)";

	long_desc=
	
	"You find yourself on top of a sizeable hill. The ground here looks\n"
"quite dirty, To the north lays smooth tracking, and the south tends to get\n"
"more bumpy.\n";

	dest_dir=({
	"/players/calvyn/body/room8.c", "north"
	"/players/calvyn/body/room10.c", "south"
	});

	items=({ 
	"ground","The ground here is dirty, just like your knees.\n",
	"gap","The gap between you and the other side is getting smaller.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The air here smells like old dirt.";
    }
}

init()
{
    ::init();
}
