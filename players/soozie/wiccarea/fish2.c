#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "C'mere and gimme a hug! (e,w)";

	long_desc=
	"This tank is quite a bit larger than the last one.  You wonder if it houses\n"
"just one big animal or a whole bunch of little ones.  As a squid swims by,\n"
"your question is answered\n";

	dest_dir=({
	"/players/soozie/wiccarea/fish1.c","west",
	"/players/soozie/wiccarea/fish3.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The salty air stings your nose";
    }
}

init()
{
    ::init();
}
