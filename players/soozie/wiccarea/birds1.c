#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Bullseye! (n,s).";

	long_desc=
	"This room was built for mant small birds.  Their songs echo off the walls\n"
"and through the trees and relax you.  Though you hear a more vicious call from\n"
"the south, you feel like you could stay here all day.  Just watch what you\n"
"stand under!!\n";

	dest_dir=({
	"/players/soozie/wiccarea/hall2.c","north",
	"/players/soozie/wiccarea/birds2.c","south",
	});

	items=({ 
	"trees","Of many varieties, the trees provide shade and shelter to many birds.\n"
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "MMMmm...lush foliage smells sweet and fresh!";
    }
}

init()
{
    ::init();
}
