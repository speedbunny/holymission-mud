#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "A horse of a different coat pattern. (sw,e)";

	long_desc=
	"Ah, the grassy plains.  Lush green grass grows everywhere, and a small \n"
"pond keeps everything green.  A few trees offer shelter when necessary.\n"
"A small herd of zebra graze quietly nearby.\n";

	dest_dir=({
	"/players/soozie/wiccarea/outside3.c","southwest",
	"/players/soozie/wiccarea/equine2.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The fresh air mixes with the sweet grass.";
    }
}

init()
{
    ::init();
}
