#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Nessie? P'shaw!! (w)";

	long_desc=
	"If you thought the squid's tank was wet, grab your towel.  This room isn't \n"
"even inside anymore - and you're standing above a lake.  It's a bit foggy\n"
"here, which you find rather odd.  What was that movement over there? Watch out!\n";

	dest_dir=({
	"/players/soozie/wiccarea/fish2.c","west",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells kinda swampy here..";
    }
}

init()
{
    ::init();
}
