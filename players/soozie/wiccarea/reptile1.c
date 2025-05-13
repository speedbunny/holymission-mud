#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "How many lizards can you find? (n,s)";

	long_desc=
	"This room is rather warm, and you can't understand why, since there doesn't\n"
"seem to be anything living here.  Then, some movement catches your eye and you\n"
"realise this room is full of chameleons!\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall3.c","north",
	"/players/soozie/wiccarea/reptile2.c","south",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The heat and dampness give for a rather unpleasant smell..";
    }
}

init()
{
    ::init();
}
