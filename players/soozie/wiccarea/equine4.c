#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

short_desc = "Eat your heart out, Anheiser Busch. (w)";

	long_desc=
	"You wonder what exactly lives here.  You search and search the room,\n"
"but find nothing.  Then, on the ground you see a shadow approaching and\n"
"growing larger.  Just as you look up, a hoof strikes your head!\n";

	dest_dir=({
	"/players/soozie/wiccarea/equine3.c","west",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Like you have time to smell anything!";
    }
}

init()
{
    ::init();
}
