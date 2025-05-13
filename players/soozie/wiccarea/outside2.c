#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Not much to see here, folks...(e,w)";

	long_desc=
	"The courtyard continues east and west.  To the north, a boardwalk is being\n"
"built into the woods.  Perhaps a new exhibit?  You can't tell from here ,\n"
"because, as it is under construction, it is closed off from the public.  To\n"
"the east and west are the exhibits that are popular already.\n";

	dest_dir=({
	"/players/soozie/wiccarea/outside1.c", "west",
	"/players/soozie/wiccarea/outside3.c", "east"
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The smell of animals is nonexistent here.";
    }
}

init()
{
    ::init();
}
