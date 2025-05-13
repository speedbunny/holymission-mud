#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "What a cute kitty! Is it friendly? (e,w)";

	long_desc=
	"This room looks a lot like the lions' room.  However, there are more trees\n"
"and less rock here.  There are also more bones lying about.  As you scan the\n"
"room, a low, menacing growl emanates from a thicket of grass you'd overlooked\n"
"before...\n";

	dest_dir=({
	"/players/soozie/wiccarea/felid1.c","east",
	"/players/soozie/wiccarea/felid3.c","west",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The smell of lush grass mixes with that of dried blood.";
    }
}

init()
{
    ::init();
}
