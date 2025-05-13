#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room5. (nw,s)";

	long_desc=
	
	"The area here is pleasent. The sky is blue and the birds are out\n"
"singing, but there are no trees. The gap that stops you from going west\n" 
"seems to close up ahead. You notice the ground getting kinda wrinkly up ahead\n"
"maybe you should investigate it.\n";

	dest_dir=({
	"/players/calvyn/body/room6.c", "northwest"
	"/players/calvyn/body/room4.c", "south"
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
