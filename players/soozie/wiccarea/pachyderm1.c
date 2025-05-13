#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Anybody want a peanut? (e,w)";

	long_desc=
	"Yay!  It's the elephants!  Everyone loves the elephants.  They're quiet,\n"
"and so wrinkly!  The elephants here graze peacefully.  You see a few\n"
"taking baths in the pond.\n";

	dest_dir=({
	"/players/soozie/wiccarea/outside3.c","west",
	"/players/soozie/wiccarea/pachyderm2.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "You can smell peanuts!";
    }
}

init()
{
    ::init();
}
