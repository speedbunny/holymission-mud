#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "In the jungle, the mighty jungle...(e,w)";

	long_desc=
	"This room looks like the plains.  Tall grass grows from sandy soil, and the\n"
"air is dry.  A few outcroppings of rock offer shelter from the elements.  A\n"
"lion and his lioness lie on the rock, enjoying the warmth of the sun.  They\n"
"keep their eyes on you, though.\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall4.c","east",
	"/players/soozie/wiccarea/felid2.c","west"
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "You think you smell cat...";
    }
}

init()
{
    ::init();
}
