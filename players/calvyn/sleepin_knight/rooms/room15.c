#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room15 (w,se)";

	long_desc=
	
	"Long Desc\n"
"More Long Desc\n"
"More Long Desc.\n";

	dest_dir=({
	"/players/calvyn/body/room14.c", "west"
	"/players/calvyn/body/room16.c", "southeast"
	});

	items=({ 
	"item","item desc\n",
	"item","item desc\n",
	"item","item desc\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "smell";
    }
}

init()
{
    ::init();
}
