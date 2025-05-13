#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "A hallway (n, s, w)";

	long_desc=
	"As you enter this section of the hallway, a loud growl startles you.\n"
"More growling comes from the west, where the outdoor felid exhibit is.  The\n"
"hall continues south, but to the north you can go outside into a courtyard.\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall3.c","south",
	"/players/soozie/wiccarea/felid1.c","west",
	"/players/soozie/wiccarea/outside1.c","north",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells like a hallways.";
    }
}

init()
{
    ::init();
}
