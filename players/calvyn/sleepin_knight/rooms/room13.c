#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room13. (n,s)";

	long_desc=
	
	"You have ultimately found serenity amoung this land mass. The ground\n"
"here is still of unknown substance. To the north you notice an intersection\n"
"and to the south you hear a rumbling noise.\n";

	dest_dir=({
	"/players/calvyn/body/room14.c", "north"
	"/players/calvyn/body/room12.c", "south"
	});

	items=({ 
	"ground","The ground here is soft and strange.\n",
	"intersection","An intersection lays to the north.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "The are is clean and fresh here.";
    }
}

init()
{
    ::init();
}
