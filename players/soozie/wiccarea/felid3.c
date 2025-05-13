#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Here, kitty kitty...(e)";

	long_desc=
	"This room was designed to look like a forest, and it does!  It's a bit\n"
"darker here, but as youe eyes adjust to the light, a large figure leaps at \n"
"you from the shadows!!\n";

	dest_dir=({
	"/players/soozie/wiccarea/felid2.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Ahhh...the fresh scent of pine!";
    }
}

init()
{
    ::init();
}
