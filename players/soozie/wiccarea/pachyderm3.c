#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "EEK! A mouse!! (w)";

	long_desc=
	"The tusk marks in the rock tell you right away that this animal either wants\n"
"out or just doesn't enjoy company.  Better check behind you!\n";

	dest_dir=({
	"/players/soozie/wiccarea/pachyderm2.c","west",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Like you have time to smell anything.";
    }
}

init()
{
    ::init();
}
