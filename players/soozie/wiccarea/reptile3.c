#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "I am the lizard king..(n)";

	long_desc=
	"Well for as wet as it was in the last room, it's that DRY in here. You feel\n"
"like you've walked straight into the hottest, driest desert ever!  You can see\n"
"the heat rising off of the ground.  Nothing but sand and rocks in here.  And you\n"
"think that the animal that lives here undoubtedly eats meat.  A shadow passes\n"
"over you and as you focus on it, you see the biggest dragon you've ever encountered!\n";

	dest_dir=({
	"/players/soozie/wiccarea/reptile2.c","north",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
smell = "All you smell here is heat and dryness.";
    }
}

init()
{
    ::init();
}
