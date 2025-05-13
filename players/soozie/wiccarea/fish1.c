#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Fishsticks! (e,w)";

	long_desc=
	"You walk above a tank that holds many small fishes.  What can you say, \n"
"they're not all that exciting.  Nevertheless, they deserve their own exhibit\n"
"as well.  Besides, you'll need the practice you'll get here if you plan on\n"
"seeing the other fish exhibits.\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall5.c","west",
	"/players/soozie/wiccarea/fish2.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells kinda fishy...";
    }
}

init()
{
    ::init();
}
