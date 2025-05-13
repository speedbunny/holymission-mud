#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Calvyn's Area Entrance. (upw,upe)";

	long_desc=
	
	"You find yourself standing between two large objects. There are two ropes\n"
"here, one seems to go up and to the east while the other goes up and west.\n"
"You smell a familiar scent but you cannot place it. There is also a sign here.\n";

	dest_dir=({
	"/players/calvyn/body/room2.c", "upeast"
	"/players/calvyn/body/room8.c", "upwest"
	});

	items=({ 
	"rope","A sturdy rope, strong enough to climb.\n",
	"object","There is something on the object, it reads, 'Timberland'\n",
	"sign","A wooden sign, maybe you can read it.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "'Phew!' It smells like a gym locker room.";
    }
}

init()
{
    ::init();
}
