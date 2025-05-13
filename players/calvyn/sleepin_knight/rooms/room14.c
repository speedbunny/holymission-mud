#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room 14. (n,e,s,w)";

	long_desc=
	
	"You have come to an intersection in this land.\n"
"More Long Desc\n"
"More Long Desc.\n";

	dest_dir=({
	"/players/calvyn/body/room21.c", "north"
	"/players/calvyn/body/room15.c", "east"
	"/players/calvyn/body/room13.c", "south"
	"/players/calvyn/body/room18.c", "west"
	});

	items=({ 
	"item","item desc\n",
	"item","item desc\n",
	"item","item desc\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The air here smell fresh.";
    }
}

init()
{
    ::init();
}
