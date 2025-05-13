#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "A hallway (n,s,e)";

	long_desc=
	"Here the halllway turns, going north and east.  To the south, the reptiles\n"
"are housed.  You can still heat many animals\n"
"calling from other exhibits.\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall2.c","east",
	"/players/soozie/wiccarea/reptiles1.c","south",
	"/players/soozie/wiccarea/hall4.c","north",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells like the foliage used in the reptile exhibit";
    }
}

init()
{
    ::init();
}
