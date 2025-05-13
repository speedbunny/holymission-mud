#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "An elephant never forgets! (e,w)";

	long_desc=
	"Wow.  And you thought regular ol' elephants were big.  The wooly mammoth\n"
"housed here is HUGE!  It's really hairy, too.  Not as cute as the elephants\n"
"eh?\n";

	dest_dir=({
	"/players/soozie/wiccarea/pachyderm1.c","west",
	"/players/soozie/wiccarea/pachyderm3.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "It's starting to smell a little unpleasant here.";
    }
}

init()
{
    ::init();
}
