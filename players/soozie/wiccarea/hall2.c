#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "A hallway (s,w,e).";

	long_desc=
	"As you walk through here, you hear the sounds of many birds coming from the\n"
"south.  Their songs float to you and you suddenly feel at ease.  Perhaps you\n"
"should go check it out?  The hallway continues west and east.\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall1.c","east",
	"/players/soozie/wiccarea/birds1.c","south",
	"/players/soozie/wiccarea/hall3.c","west",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The scent of birds is a bit stronger here.";
    }
}

init()
{
    ::init();
}
