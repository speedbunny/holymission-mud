#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Tweety by any other name...(n)";

	long_desc=
	"This room is filled with many Soozie trees.  The infamous phoenix is rumored\n"
"to be housed here.  However, as you scan the room, you dont' see anything.  Perhaps\n"
"you should wait and see what happens....\n";

	dest_dir=({
	"/players/soozie/wiccarea/birds2.c","north",
	});

	items=({ 
	"trees","Tall and beautiful, this is where the phoenix is reborn.\n"
	"branches","Most are dead or dying from having their bark stripped by claws.\n"
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "funny, but it really doesn't smell like anything here.";
    }
}

init()
{
    ::init();
}
