#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "A Hallway (n,s,w).";

	long_desc=
	"This is a short hallway that connects the different rooms leading to various\n"
	"exhibits.  It continues north and west.  To the south you can see the\n"
	"entrance to the zoo.  You hear the calls of the many animals that are housed\n"
	"here.\n";

	dest_dir=({
	  "/players/soozie/wiccarea/entrance.c","south",
	  "/players/soozie/wiccarea/hall5.c","north",
	  "/players/soozie/wiccarea/hall2.c","west"
	});

	items=({ 
	  "stream","The water is cool, and it sparkles in the sun.",
	  "path","It has become more faded than it is north of here.",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "You think you catch the smell of...animals...in the air.";
    }
}

init()
{
    ::init();
}
