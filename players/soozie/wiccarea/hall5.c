#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc =  "A hallway (n,s,e)";

	long_desc=
	"Here you can see the courtyard to the north, and the zoo entrance far to\n"
"the south.  To the east is the aquarium.\n";

	dest_dir=({
	"/players/soozie/wiccarea/outside3.c","north",
	"/players/soozie/wiccarea/fish1.c","east",
	"/players/soozie/wiccarea/hall1.c","south",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells like a hallway, with a tinge of seawater...";
    }
}

init()
{
    ::init();
}
