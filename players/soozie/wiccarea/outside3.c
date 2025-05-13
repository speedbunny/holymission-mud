#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Oh, the choices! (w,e,s,ne)";

	long_desc=
	"Here the courtyard begins and stretches off to the west.  To the\n"
"northeast is the equine exhibit, and the pachiderm exhibit is east.  The \n"
"hallway begins to the south.\n";

	dest_dir=({
	"/players/soozie/wiccarea/outside2.c","west",
	"/players/soozie/wiccarea/equine1.c","northeast",
	"/players/soozie/wiccarea/pachyderm1.c","east",
	"/players/soozie/wiccarea/hall5.c","south",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The fresh air mixes with the faint stench of animals";
    }
}

init()
{
    ::init();
}
