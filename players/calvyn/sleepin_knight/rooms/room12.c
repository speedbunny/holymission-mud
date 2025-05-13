#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room12. (n,se,sw)";

	long_desc=
	
	"You find yourself on top of a large hill and at the fork of this land\n" 
"mass. The ground remains quite contoured. Also you notice that you have found\n" 
"the cause of this terrible rumbling noise. To the north the area seems more\n" 
"peaceful.\n";

	dest_dir=({
	"/players/calvyn/body/room13.c", "north"
	"/players/calvyn/body/room6.c", "southeast"
	"/players/calvyn/body/room7.c", "southwest"
	});

	items=({ 
	"hill","The hill seems to be a large soft mass of unknown substance.\n",
	"ground","The ground is soft here.\n",
	"fork","The fork to the south goes southwest and southeast.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "You fail to smell any odor.";
    }
}

init()
{
    ::init();
}
