#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "My, what big teeth you have! (n,s)";

	long_desc=
	"Ack.  Wet and sweaty, you seem to have walked into what is supposed to be a\n"
"swamp.  Luckily, the wooden bridge upon which you stand isn't submerged.  However,\n"
"you're only about two feet above the water.  Hope the crocodiles they keep here\n"
"have been fed today...\n";

	dest_dir=({
	"/players/soozie/wiccarea/reptile1.c","north",
	"/players/soozie/wiccarea/reptile3.c","south",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "This room smells worse than the last!";
    }
}

init()
{
    ::init();
}
