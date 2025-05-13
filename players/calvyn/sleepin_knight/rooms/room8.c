#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room8. (ne,s)";

	long_desc=
	
	"The area here is pleasent. The sky is blue and the birds are out\n"
"singing, but there are no trees. The gap that stops you from going east\n" 
"seems to close to the north and the ground gets kinda wrinkly.\n";

	dest_dir=({
	"/players/calvyn/body/room7.c", "northeast"
	"/players/calvyn/body/room9.c", "south"
	});

	items=({ 
	"ground","The ground here almost seems like fabric here.\n",
	"birds","High altitude birds fly about.\n",
	"sky","The sky it a deep blue and the clouds don't seem far away.\n",
	"gap","The gap to the west closes up ahead.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The air here smells fresh and clean";
    }
}

init()
{
    ::init();
}
