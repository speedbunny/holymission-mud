#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room4. (n,s)";

	long_desc=
	
	"You find yourself on top of a sizable hill. The ground here looks\n"
"quite dirty. Smooth tracking lies to the north while it gets more bumpy\n"
"towards the south.\n";

	dest_dir=({
	"/players/calvyn/body/room5.c", "north"
	"/players/calvyn/body/room3.c", "south"
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
