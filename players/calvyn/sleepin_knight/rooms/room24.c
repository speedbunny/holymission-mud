#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room24 (ne,e,se)";

	long_desc=
	
	"Long Desc\n"
"More Long Desc\n"
"More Long Desc.\n";

	dest_dir=({
	"/players/calvyn/body/room25.c", "northeast"
	"/players/calvyn/body/room23.c", "east"
	"/players/calvyn/body/room22.c", "southeast"
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
