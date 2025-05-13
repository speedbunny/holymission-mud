#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Zoo Entrance (n,s)";

	long_desc=
	
	"This is a rather plain room.  The walls are white and there is an\n"
"information desk in one corner.  The desk is empty right now, and there\n"
"are a few ads on the walls for upcoming programs here at the zoo.\n"
	"There is a SIGN here that you should read.\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall1.c", "north"
	});

	items=({ 
	"desk","A small wooden desk with a few papers on it.\n",
	"ads","Colored posters hanging on the walls announcing future events.\n",
	"sign","Maybe you should read it?\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells like any other small plain room you've ever been in...";
    }
}

init()
{
    ::init();
}
