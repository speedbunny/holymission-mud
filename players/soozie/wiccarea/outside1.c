#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "A large courtyard (s,e)";

	long_desc=
	"Here is a small courtyard that can take you to other exhibits without \n"
"having to go back through the hallway.  The yard continues east and the hallway\n"
"is to the south\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall4.c","south",
	"/players/soozie/wiccarea/outside2.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The great outdoors...";
    }
}

init()
{
    ::init();
}
